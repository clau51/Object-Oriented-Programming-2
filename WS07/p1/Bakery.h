#ifndef SDDS_BAKERY_H_
#define SDDS_BAKERY_H_
#include <string>
#include <iostream>
#include <vector>
namespace sdds
{
   enum class BakedType
   {
      BREAD,
      PASTRY
   };

   struct BakedGood
   {
      BakedType m_bakedType{};
      std::string m_description{};
      size_t m_shelfLife{};
      size_t m_stock{};
      double m_price{};
   };

   class Bakery
   {
      std::vector<BakedGood> m_bakedGoods{};
      std::string& trim(std::string& s)
      {
         int first = s.find_first_not_of(' ');
         int last = s.find_last_not_of(' ');

         s.erase(0, first);
         s.erase(last + 1 - first);
         return s;

      }
   public:
      Bakery(const std::string& filename);
      void showGoods(std::ostream& os) const;
   };

   std::ostream& operator<<(std::ostream& out, const BakedGood& b);
}
#endif