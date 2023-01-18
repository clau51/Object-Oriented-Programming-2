#ifndef SDDS_FOODORDER_H_
#define SDDS_FOODORDER_H_
#include <iostream>

extern double g_taxrate;
extern double g_dailydiscount;

namespace sdds
{
   class FoodOrder
   {
      char m_name[9 + 1];
      char m_description[24 + 1];
      double m_price;
      char m_onSpecial;
      void setEmpty();
      bool isEmpty()const;
   public:
      FoodOrder();
      std::istream& read(std::istream& istr = std::cin);
      std::ostream& display(std::ostream& ostr = std::cout)const;
   };
}
#endif


































//namespace sdds
//{
//   class Food
//   {
//      char* m_name;
//      int m_time;
//      bool m_valid;
//   public:
//      Food();
//      Food(const char* name, int time);
//      ~Food();
//      void setEmpty();
//      bool isValid()const;
//      int getTime()const;
//      void display()const;
//   };
//}
//}
