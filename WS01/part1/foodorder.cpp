#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include "foodorder.h"

double g_taxrate = 0;
double g_dailydiscount = 0;

using namespace std;
namespace sdds
{
   void FoodOrder::setEmpty()
   {
      m_name[0] = '\0';
      m_description[0] = '\0';
      m_price = 0.0;
      m_onSpecial = 'N';
   }

   bool FoodOrder::isEmpty()const
   {
      return !m_name[0];
   }

   FoodOrder::FoodOrder()
   {
      m_name[0] = '\0';
      m_description[0] = '\0';
      m_price = 0.0;
      m_onSpecial = 'N';
   }

   std::istream& FoodOrder::read(std::istream& istr)
   {
      if (istr)
      {
         istr.getline(m_name, 10, ',');
         istr.getline(m_description, 25, ',');
         istr >> m_price;
         istr.ignore();
         istr >> m_onSpecial;
         istr.ignore(1000, '\n');

         if (!(m_price >= 0))
         {
            setEmpty();
         }
      }

      if (!istr)
      {
         setEmpty();
         istr.clear();
         istr.ignore(1000, ',');
      }

      return istr;
   }
   std::ostream& FoodOrder::display(std::ostream& ostr) const
   {
      static int counter = 1;

      ostr.setf(ios::left);
      ostr.width(2);
      ostr << counter << ". ";
      if (!isEmpty())
      {
         ostr.width(10);
         ostr << m_name;
         ostr << "|";
         ostr.width(25);
         ostr << m_description;
         ostr << "|";
         ostr.width(12);

         double priceAfterTax = m_price * (1 + g_taxrate);
         ostr.setf(ios::fixed);
         ostr.precision(2);
         ostr << priceAfterTax;
         ostr << "|";
         ostr.unsetf(ios::left);
         if (m_onSpecial == 'Y')
         {
            ostr.width(13);
            ostr.setf(ios::right);
            ostr << priceAfterTax - g_dailydiscount;
            ostr.unsetf(ios::right);
         }
         ostr.unsetf(ios::fixed);
      }
      else
      {
         ostr << "No Order";
      }

      ostr << endl;
      counter++;


      return ostr;
   }
}
//char tempName[10];
//istr.getline(tempName, 10, ','); //read up to 9 meaningful characters along with a nullbyte
//if (tempName && tempName[0])
//{
//   m_name = new char[strlen(tempName) + 1];
//   strcpy(m_name, tempName);
//}
//
//char tempDesc[10];
//istr.getline(tempDesc, 25, ',');
//if (tempDesc && tempDesc[0])
//{
//   m_description = new char[strlen(tempDesc) + 1];
//   strcpy(m_description, tempDesc);
//}

//double tempPrice;
//istr >> tempPrice;
//if (tempPrice >= 0)
//{
//   m_price = tempPrice;
//}

//istr.ignore();
//istr >> m_onSpecial;
//istr.ignore(1000, '\n');