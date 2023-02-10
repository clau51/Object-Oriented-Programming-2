#include "ConfirmOrder.h"

namespace sdds
{
   ConfirmOrder& ConfirmOrder::operator+=(const Toy& toy)
   {
      toy.m_arrPtr = 
   }
   ConfirmOrder& ConfirmOrder::operator-=(const Toy& toy)
   {
      // // O: insert return statement here
   }
   std::ostream& operator<<(std::ostream& ostr, const ConfirmOrder& confirmOrder)
   {
      return ostr;
   }
}