#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "Utilities.h"
#include "LineManager.h"
#include "Workstation.h"

using namespace std;
namespace sdds
{
   //receive filename, collection of Workstations available for configuring assembly line
   sdds::LineManager::LineManager(const std::string& filename, const std::vector<Workstation*>& stations)
   {
      ifstream file(filename);
      Utilities utils{};
      string tempString{};
      //vector<Workstation*> tempWorkStation{};
      int addedToActive{};

      if (file)
      {
         while (file.peek() != EOF)
         {
            bool more{};
            size_t pos{};
            getline(file, tempString);
            string tempStation{};
            string tempNextStation{};
            tempStation = utils.extractToken(tempString, pos, more);
            if (more)
            {
               tempNextStation = utils.extractToken(tempString, pos, more);
            }
            else
            {
               tempNextStation = "End of Line";
            }

            bool exit{};
            for (size_t i = 0; i < stations.size() && !exit; i++)
            {
               if (tempStation == stations[i]->getItemName())
               {
                  m_activeLine.push_back(stations[i]);

                  //loop to find if tempnextstation is equal to any of the stations in the collection; if it does, set the pointer
                  //to the next station to point to that station
                  for (size_t j = 0; j < stations.size() && !exit; j++)
                  {
                     if (tempNextStation == stations[j]->getItemName())
                     {
                        m_activeLine[addedToActive++]->setNextStation(stations[j]);
                        exit = true;
                     }
                     else if (tempNextStation == "End of Line")
                     {
                        m_activeLine[addedToActive++]->setNextStation(nullptr);
                        exit = true;
                     }
                  }
               }
            }
         }

         //create a list of "next" stations
         vector<string> listOfNextStations{};
         for (size_t i = 0; i < m_activeLine.size(); i++)
         {
            if (m_activeLine[i]->getNextStation() != nullptr)
            {
               listOfNextStations.push_back(m_activeLine[i]->getNextStation()->getItemName());
            }
         }

         bool exitNow{};
         for (size_t i = 0; i < m_activeLine.size() && !exitNow; i++)
         {
            int nextCounter{};
            for (size_t j = 0; j < listOfNextStations.size(); j++)
            {
               if (m_activeLine[i]->getItemName() == listOfNextStations[j])
               {
                  nextCounter++;
               }
            }

            if (nextCounter == 0)
            {
               m_firstStation = m_activeLine[i];
               exitNow = true;
            }
         }

         m_cntCustomerOrder = g_pending.size();
      }
      else
      {
         throw std::string("error");
      }
   }

   void sdds::LineManager::reorderStations()
   {
      vector<Workstation*> tempActiveLine{};
      tempActiveLine.push_back(m_firstStation); 

      Workstation* currentWorkstation = tempActiveLine.back();

      for (int i = 0; i < m_activeLine.size(); i++)
      {
         bool isNext{};
         currentWorkstation = tempActiveLine.back();
         for (int i = 0; i < m_activeLine.size() && !isNext; i++)
         {
            if (currentWorkstation->getNextStation() != nullptr)
            {
               if (currentWorkstation->getNextStation()->getItemName() == m_activeLine[i]->getItemName())
               {
                  tempActiveLine.push_back(m_activeLine[i]);
                  isNext = true;
               }
            }
         }
      }

      //for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* ws) {
      //   currentWorkstation = tempActiveLine.back();
      //   if (currentWorkstation->getNextStation())
      //   });

      //for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* ws) {
      //   currentWorkstation = tempActiveLine.back();
      //   currentWorkstation = tempActiveLine.back();
      //   copy_if(m_activeLine.begin(), m_activeLine.end(), back_inserter(tempActiveLine), [&](Workstation* ws) {

      //      bool ok{};
      //      if (currentWorkstation->getNextStation() != nullptr)
      //      {
      //         ok = currentWorkstation->getNextStation()->getItemName() == ws->getItemName();
      //      }

      //      return ok;
      //      });
      //   });

      m_activeLine = tempActiveLine;
   }

   bool sdds::LineManager::run(std::ostream& os)
   {
      static int count = 1;

      os << "Line Manager Iteration: " << count++ << endl;

      if (!g_pending.empty()) //if not empty
      {
         *m_firstStation += move(g_pending.front());
         g_pending.pop_front();
      }

      for (size_t i = 0; i < m_activeLine.size(); i++)
      {
         m_activeLine[i]->fill(os);
      }

      for (size_t i = 0; i < m_activeLine.size(); i++)
      {
         m_activeLine[i]->attemptToMoveOrder();
      }

      return g_completed.size() + g_incomplete.size() == m_cntCustomerOrder ? true : false;
   }

   void sdds::LineManager::display(std::ostream& os) const
   {
      for (size_t i = 0; i < m_activeLine.size(); i++)
      {
         m_activeLine[i]->display(os);
      }
   }

}