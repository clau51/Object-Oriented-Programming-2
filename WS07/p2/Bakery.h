//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: Mar 18, 2023
//Section: NDD
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_BAKERY_H_
#define SDDS_BAKERY_H_
#include <string>
#include <iostream>
#include <vector>
#include <list>
namespace sdds
{
   enum class BakedType
   {
      BREAD,
      PASTERY
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
      std::string& trim(std::string& s);
   public:
      Bakery(const std::string& filename);
      void showGoods(std::ostream& os) const;
      void sortBakery(const std::string& field);
      std::vector<BakedGood> combine(Bakery& bakery);
      bool inStock(const std::string& description, const BakedType& bakedType) const;
      std::list<BakedGood> outOfStock(const BakedType& bakedType) const;
   };

   std::ostream& operator<<(std::ostream& out, const BakedGood& b);
}
#endif