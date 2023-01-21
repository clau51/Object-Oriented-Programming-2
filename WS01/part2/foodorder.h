//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: January 16, 2022
//Section: NDD
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_FOODORDER_H_
#define SDDS_FOODORDER_H_
#include <iostream>

extern double g_taxrate;
extern double g_dailydiscount;

namespace sdds
{
   class FoodOrder
   {
      char m_name[9 + 1]{};
      char* m_description{};
      double m_price{};
      bool m_onSpecial{};

      FoodOrder& setEmpty();
      bool isEmpty()const;
      FoodOrder& deallocate();
      operator bool()const;
   public:
      FoodOrder() = default;
      FoodOrder(const FoodOrder& foodOrder);
      ~FoodOrder();
      FoodOrder& operator=(const FoodOrder& foodOrder);
      std::istream& read(std::istream& istr = std::cin);
      std::ostream& display(std::ostream& ostr = std::cout)const;
   };
}
#endif