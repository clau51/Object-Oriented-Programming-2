//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: Mar 12, 2023
//Section: NDD
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <string>
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

      m_lstItem = new Item* [m_cntItem];
      while(more)
      {
         m_lstItem[m_cntItem++] = new Item(utils.extractToken(s, position, more));
      }

      if (CustomerOrder::m_widthField < utils.getFieldWidth())
      {
         CustomerOrder::m_widthField = utils.getFieldWidth();
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

         m_widthField = customerOrder.m_widthField; //do i need this?
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
      //An order can have multiple items..
      //A station works on one item at a time
      for (size_t i = 0; i < m_cntItem; i++)
      {
         if (station.getItemName() == m_lstItem[m_cntItem]->m_itemName)
         {

         }
      }

   }
   void CustomerOrder::display(std::ostream& ost) const
   {
   }
}






//
//if (station.getItemName() == m_lstItem[0]->m_itemName)
//{
//   station.updateQuantity();
//   m_lstItem[0]->m_serialNumber = station.getNextSerialNumber();
//   m_lstItem[0]->m_isFilled = true;
//   os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[0]->m_itemName << "]" << endl;
//}