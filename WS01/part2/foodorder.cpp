//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: January 16, 2022
//Section: NDD
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <cstring>
#include "foodorder.h"

double g_taxrate = 0.0;
double g_dailydiscount = 0.0;

using namespace std;
namespace sdds
{
   FoodOrder& FoodOrder::setEmpty()
   {
      m_description = nullptr;
      m_name[0] = '\0';
      m_price = 0.0;
      m_onSpecial = false;

      return *this;
   }

   bool FoodOrder::isEmpty()const
   {
      return !m_name[0];
   }

   FoodOrder::operator bool() const
   {
      return m_name[0];
   }

   FoodOrder& FoodOrder::deallocate()
   {
      delete[] m_description;
      m_description = nullptr;

      return *this;
   }

   FoodOrder::~FoodOrder()
   {
      delete[] m_description;
   }

   FoodOrder::FoodOrder(const FoodOrder& foodOrder)
   {
      *this = foodOrder;
   }

   FoodOrder& FoodOrder::operator=(const FoodOrder& foodOrder)
   {
      if (this != &foodOrder)
      {
         if (foodOrder)
         {
            deallocate();

            strcpy(m_name, foodOrder.m_name);
            m_description = new char[strlen(foodOrder.m_description) + 1];
            strcpy(m_description, foodOrder.m_description);
            m_price = foodOrder.m_price;
            m_onSpecial = foodOrder.m_onSpecial;
         }
      }

      return *this;
   }

   std::istream& FoodOrder::read(std::istream& istr)
   {
      string description;
      if (istr)
      {
         istr.getline(m_name, 10, ',');

         getline(istr, description, ','); 
         deallocate();
         m_description = new char[description.length() + 1];
         strcpy(m_description, description.c_str());

         istr >> m_price;
         istr.ignore();

         char tempSpecial = istr.get();
         if (tempSpecial == 'Y')
         {
            m_onSpecial = true;
         }
         else if (tempSpecial == 'N')
         {
            m_onSpecial = false;
         }

         istr.ignore(1000, '\n');
      }

      if (!istr)
      {
         delete[] m_description;
         setEmpty();

         istr.clear();
         istr.ignore(1000, '\n');
      }
      return istr;
   }

   std::ostream& FoodOrder::display(std::ostream& ostr) const
   {
      static int counter = 1;

      //Can also use the iomanip library to use setw, width, right, fixed, left
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
         if (m_onSpecial)
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

