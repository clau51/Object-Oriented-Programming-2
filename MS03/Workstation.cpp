#include <iostream>
#include "Workstation.h"

using namespace std;
namespace sdds
{
   std::deque<CustomerOrder> g_pending{}; //hold orders to be placed onto assembly line at first station
   std::deque<CustomerOrder> g_completed{}; //hold orders that have been REMOVED from last station (fullfilled)
   std::deque<CustomerOrder> g_incomplete{}; //hold orders that have been REMOVED from last station (unfulfilled)

   Workstation::Workstation(const std::string s) : Station(s)
   {

   }

   void Workstation::fill(std::ostream& os) //use members from base class
   {
      if (!m_orders.empty()) //if there are orders in the queue (not empty)
      {
         m_orders.front().fillItem(*this, os); //fill order at the front of queue
      }
   }

   //move order at front of m_orders to next station in assembly line
   bool Workstation::attemptToMoveOrder()
   {
      bool moved{};

      if (!m_orders.empty()) //check if m_orders has something
      {
         //if no more service needed, or not enough inventory to service
         //when does it require no more service at this station? -> item is filled, 
         //item is not in customer order (both handled by isItemFilled; 
         //returns false if item is partially filled)
         if (getQuantity() == 0 || m_orders.front().isItemFilled(getItemName()))
         {
            if (!m_pNextStation) //if next station doesnt exist (end of line)
            {
               if (m_orders.front().isOrderFilled()) //check if whole order filled
               {
                  g_completed.push_back(move(m_orders.front())); //push front element of m_orders to back of g_completed
               }
               else //if order partially filled/incomplete
               {
                  g_incomplete.push_back(move(m_orders.front())); //push front element to m_incomplete
               }
            }
            else //move to the next station
            {
               //at the next station, add current order to m_orders (moved to next station)
               *m_pNextStation += move(m_orders.front());
            }
            m_orders.pop_front();
            moved = true;
         }
      }

      return moved;
   }

   void Workstation::setNextStation(Workstation* station)
   {
      m_pNextStation = station;
   }

   Workstation* Workstation::getNextStation() const
   {
      return m_pNextStation;
   }

   void Workstation::display(std::ostream& os) const
   {
      os << getItemName() << " --> ";
      if (m_pNextStation)
      {
         os << m_pNextStation->getItemName() << endl;
      }
      else
      {
         os << "End of Line" << endl;
      }
   }

   Workstation& Workstation::operator+=(CustomerOrder&& newOrder)
   {
      //move new order to back of queue
      m_orders.push_back(move(newOrder));
      return *this;
   }


}