#ifndef SDDS_LINEMANAGER_H_
#define SDDS_LINEMANAGER_H_
#include <vector>
#include <iostream>
#include "Workstation.h"
namespace sdds
{
   class LineManager
   {
      std::vector<Workstation*> m_activeLine{}; //collection of workstations for the current assembly line
      size_t m_cntCustomerOrder{}; //total num of CustomerOrder objects
      Workstation* m_firstStation{}; //pointer to first ACTIVE station on current line

   public:
      LineManager(const std::string& file, const std::vector<Workstation*>& stations);
      void reorderStations();
      bool run(std::ostream& os);
      void display(std::ostream& os) const;
   };
}

#endif

