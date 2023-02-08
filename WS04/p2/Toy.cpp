#include <string>
#include <iostream>
#include <iomanip>
#include "Toy.h"

using namespace std;
namespace sdds
{
   std::string& Toy::trim(std::string& s)
   {
      int startIndex = 0;
      bool exit{};
      for (size_t i = 0; i < s.length() - 1 && !exit; i++)
      {
         if (s[i] == ' ')
         {
            startIndex++;
         }
         else
         {
            exit = true;
         }
      }

      int endIndex = 0;
      exit = false;
      for (int i = s.length() - 1; i >= 0 && !exit; i--)
      {
         if (s[i] == ' ')
         {
            endIndex++;
         }
         else
         {
            exit = true;
         }
      }

      return s[s.length() - 1] == ' ' ? s = s.substr(startIndex, s.length() - endIndex) : s = s.substr(startIndex, s.length() - endIndex);
   }
   void Toy::update(int numItems)
   {
      //Assume the parameter is correct and doesn't require validation
      m_noOfToys = numItems;
   }
   Toy::Toy(const std::string& toy)
   {
      string temp = toy;

      int colonIndex = temp.find(':');
      m_orderID = static_cast<unsigned int>(stoi(temp));
      temp.erase(0, colonIndex + 1);

      colonIndex = temp.find(':');
      m_toyName = temp.substr(0, temp.find(':'));

      trim(m_toyName);

      colonIndex = temp.find(':');
      temp.erase(0, colonIndex + 1);

      colonIndex = temp.find(':');
      m_noOfToys = stod(temp);
      temp.erase(0, colonIndex + 1);

      m_price = stod(temp);


   }

   std::ostream& operator<<(std::ostream& ostr, const Toy& toy)
   {
      ostr << "Toy";
      ostr << setw(8) << toy.m_orderID << ":";
      ostr << setw(18) << right << toy.m_toyName;
      ostr << setw(3) << toy.m_noOfToys << " items";
      ostr << setw(8) << toy.m_price << "/item  subtotal:";

      double subtotal = toy.m_price * toy.m_noOfToys;
      ostr << setw(7) << fixed << setprecision(2) << subtotal << " tax:";

      double tax = toy.m_tax * subtotal;
      ostr << setw(6) << tax << " total:";
      ostr << setw(7) << subtotal + tax << endl;


      return ostr;
   }
}