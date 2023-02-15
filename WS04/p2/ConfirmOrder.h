//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: Feb 7, 2023
//Section: NDD
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_CONFIRMORDER_H_
#define SDDS_CONFIRMORDER_H_

#include <iostream>
#include "Toy.h"

namespace sdds
{
   class ConfirmOrder
   {
      const Toy** m_arrPtr{};
      int m_count{};
   public:
      ConfirmOrder& operator+=(const Toy& toy);
      ConfirmOrder& operator-=(const Toy& toy);
      ConfirmOrder() = default;
      ConfirmOrder(const ConfirmOrder& confirmOrder);
      ConfirmOrder& operator=(const ConfirmOrder& confirmOrder);
      ConfirmOrder(ConfirmOrder&& confirmOrder)noexcept;
      ConfirmOrder& operator=(ConfirmOrder&& confirmOrder)noexcept;
      friend std::ostream& operator<<(std::ostream& ostr, const ConfirmOrder& confirmOrder);
      ~ConfirmOrder();
   };
}

#endif

