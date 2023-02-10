#include <iostream>
#include "Toy.h"
#ifndef SDDS_CONFIRMORDER_H_
#define SDDS_CONFIRMORDER_H_

namespace sdds
{
   class ConfirmOrder
   {
      const Toy** m_arrPtr;
   public:
      ConfirmOrder& operator+=(const Toy& toy);
      ConfirmOrder& operator-=(const Toy& toy);
      friend std::ostream& operator<<(std::ostream& ostr, const ConfirmOrder& confirmOrder);
   };
}

#endif

