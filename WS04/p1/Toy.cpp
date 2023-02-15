//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: Feb 7, 2023
//Section: NDD
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <string>
#include <iostream>
#include <iomanip>
#include "Toy.h"

using namespace std;
namespace sdds
{
   std::string& Toy::trim(std::string& s)
   {
      int first = s.find_first_not_of(' ');
      int last = s.find_last_not_of(' ');
      s.erase(0, first);
      s.erase(last + 1 - first);

      return s;
   }
   void Toy::update(int numItems)
   {
      //Assume the parameter is correct and doesn't require validation
      m_noOfToys = numItems;
   }
   Toy::Toy(const std::string& toy)
   {
      string temp = toy;

      //Order ID
      int colonIndex = temp.find(':');
      m_orderID = stoul(temp);
      temp.erase(0, colonIndex + 1);

      //Toy Name
      colonIndex = temp.find(':');
      m_toyName = temp.substr(0, temp.find(':'));
      trim(m_toyName);
      temp.erase(0, colonIndex + 1);

      //No Of Toys
      colonIndex = temp.find(':');
      m_noOfToys = stod(temp);
      temp.erase(0, colonIndex + 1);

      //Price
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