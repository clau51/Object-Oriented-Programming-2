#include "Bakery.h"
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
using namespace std;
namespace sdds
{
   Bakery::Bakery(const std::string& filename)
   {
      ifstream file(filename);

      if (!file)
      {
         throw "File not found";
      }

      while (file.peek() != EOF)
      {
         BakedGood bakedGood{};
         string tempString{};
         string tempBakeType{};
         string tempDescription{};

         getline(file, tempString);

         size_t pos = 0;
         tempBakeType = tempString.substr(pos, 8);
         trim(tempBakeType);
         pos += 8;
         if (tempBakeType == "Bread")
         {
            bakedGood.m_bakedType = BakedType::BREAD;
         }
         else if (tempBakeType == "Pastry")
         {
            bakedGood.m_bakedType = BakedType::PASTRY;
         }
         tempDescription = tempString.substr(pos, 20);
         bakedGood.m_description = trim(tempDescription);
         pos += 20;
         bakedGood.m_shelfLife = stoul(tempString.substr(pos, 14));
         pos += 14;
         bakedGood.m_stock = stoul(tempString.substr(pos, 8));
         pos += 8;
         bakedGood.m_price = stod(tempString.substr(pos));

         m_bakedGoods.push_back(bakedGood);

      }
   }
   void Bakery::showGoods(std::ostream& os) const
   {
      for_each(m_bakedGoods.begin(), m_bakedGoods.end(), [&os](auto p) {
         os << p;
         });

      size_t totalStock{};
      double totalPrice{};
      for_each(m_bakedGoods.begin(), m_bakedGoods.end(), [&os, &totalStock, &totalPrice](auto p) {
         totalStock += p.m_stock;
         totalPrice += p.m_price;
         });

      os << "Total Stock: " << totalStock << endl;
      os << "Total Price: " << totalPrice << endl;
   }
   std::ostream& operator<<(std::ostream& out, const BakedGood& b)
   {
      if (b.m_bakedType == BakedType::BREAD)
      {
         out << "* " << setw(10) << left << "Bread";
      }
      else if (b.m_bakedType == BakedType::PASTRY)
      {
         out << "* " << setw(10) << left << "Pastry";
      }

      out << " * " << setw(20) << b.m_description;
      out << " * " << setw(5) << b.m_shelfLife;
      out << " * " << setw(5) << b.m_stock;
      out << " * " << setw(8) << fixed << setprecision(2) << right << b.m_price << " * " << endl;


      return out;
   }
}