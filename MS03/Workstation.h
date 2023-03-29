#ifndef SDDS_WORKSTATION_H_
#define SDDS_WORKSTATION_H_
#include <string>
#include <deque>
#include <iostream>
#include "CustomerOrder.h"
#include "Station.h"

namespace sdds
{
   extern std::deque<CustomerOrder> g_pending; //hold orders to be placed onto assembly line at first station
   extern std::deque<CustomerOrder> g_completed; //hold orders that have been REMOVED from last station (fullfilled)
   extern std::deque<CustomerOrder> g_incomplete; //hold orders that have been REMOVED from last station (unfulfilled)

   class Workstation : public Station
   {
      std::deque<CustomerOrder> m_orders{};
      //order already placed on station to received service (or already received service)
      Workstation* m_pNextStation{}; //pointer to next Workstation on the assembly line
   public:
      Workstation(const std::string s);

      void fill(std::ostream& os);
      bool attemptToMoveOrder();
      void setNextStation(Workstation* station);
      Workstation* getNextStation()const;
      void display(std::ostream& os) const;

      //delete copy/move
      Workstation& operator +=(CustomerOrder&& newOrder);
      Workstation& operator=(const Workstation& workStation) = delete;
      Workstation(const Workstation& workStation) = delete;
      Workstation& operator=(Workstation&& workStation) = delete;
      Workstation(Workstation&& workStation) = delete;

   };
}

#endif

