//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: Mar 18, 2023
//Section: NDD
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include "CustomerOrder.h"
#include "Utilities.h"

using namespace std;
namespace sdds
{
   size_t CustomerOrder::m_widthField{};

   CustomerOrder::CustomerOrder(const std::string& s)
   {
      Utilities utils{};
      size_t position{};
      bool more{};
      m_name = utils.extractToken(s, position, more);
      m_product = utils.extractToken(s, position, more);

      vector<string> tempItems;
      while (more)
      {
         tempItems.push_back(utils.extractToken(s, position, more));
         m_cntItem++;

         if (m_widthField < utils.getFieldWidth())
         {
            m_widthField = utils.getFieldWidth();
         }
      }

      m_lstItem = new Item* [m_cntItem];

      for (size_t i = 0; i < m_cntItem; i++)
      {
         m_lstItem[i] = new Item(tempItems[i]);
      }


   }
   CustomerOrder::CustomerOrder(const CustomerOrder& customerOrder)
   {
      throw "Error: Copy Constructor cannot be called";
   }
   CustomerOrder::CustomerOrder(CustomerOrder&& customerOrder) noexcept
   {
      *this = move(customerOrder);
   }
   CustomerOrder& CustomerOrder::operator=(CustomerOrder&& customerOrder) noexcept
   {
      if (this != &customerOrder)
      {
         for (size_t i = 0; i < m_cntItem; i++)
         {
            delete m_lstItem[i];
         }
         delete[] m_lstItem;

         m_lstItem = customerOrder.m_lstItem;
         customerOrder.m_lstItem = nullptr;

         m_name = customerOrder.m_name;
         customerOrder.m_name = "";

         m_product = customerOrder.m_product;
         customerOrder.m_product = "";

         m_cntItem = customerOrder.m_cntItem;
         customerOrder.m_cntItem = 0;
      }

      return *this;
   }
   CustomerOrder::~CustomerOrder()
   {
      for (size_t i = 0; i < m_cntItem; i++)
      {
         delete m_lstItem[i];
      }
      delete[] m_lstItem;
   }

   bool CustomerOrder::isOrderFilled() const
   {
      //returns true if all the items in the order have been filled
      bool ok = true;
      for (size_t i = 0; i < m_cntItem && ok; i++)
      {
         if (m_lstItem[i]->m_isFilled == false)
         {
            ok = false;
         }
      }

      return ok;
   }
   bool CustomerOrder::isItemFilled(const std::string& itemName) const
   {
      //returns true if the item is filled
      bool ok = true;
      for (size_t i = 0; i < m_cntItem && ok; i++)
      {
         if (m_lstItem[i]->m_itemName == itemName)
         {
            if (m_lstItem[i]->m_isFilled == false)
            {
               ok = false;
            }
         }
      }

      return ok;
   }
   void CustomerOrder::fillItem(Station& station, std::ostream& os)
   {
      bool filled{};
      for (size_t i = 0; i < m_cntItem && !filled; i++)
      {
         if (station.getItemName() == m_lstItem[i]->m_itemName && station.getQuantity() > 0)
         {
            station.updateQuantity();
            m_lstItem[i]->m_isFilled = true;
            station.getNextSerialNumber(); 
            filled = true;

            if (m_lstItem[i]->m_isFilled)
            {
               os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
            }
         }
         else if (station.getItemName() == m_lstItem[i]->m_itemName && station.getQuantity() == 0)
         {
            os << "    Unable to fill " << m_name << ", " << m_product << " " << "[" << m_lstItem[i]->m_itemName << "]" << endl;
         }
      }

   }
   void CustomerOrder::display(std::ostream& ost) const
   {
      ost << m_name << " - " << m_product << endl;
      for (size_t i = 0; i < m_cntItem; i++)
      {
         ost << "[" << setw(6) << setfill('0') << m_lstItem[i]->m_serialNumber << "]" << " " << setfill(' ');
         ost << setw(m_widthField) << left << m_lstItem[i]->m_itemName << " -";
         if (m_lstItem[i]->m_isFilled)
         {
            ost << " FILLED" << endl;
         }
         else
         {
            ost << " TO BE FILLED" << endl;
         }
      }
   }
}