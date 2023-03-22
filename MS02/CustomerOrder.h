//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: Mar 18, 2023
//Section: NDD
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef SDDS_CUSTOMERORDER_H_
#define SDDS_CUSTOMERORDER_H_

#include <string>
#include "Station.h"

namespace sdds
{
   struct Item
   {
      std::string m_itemName;
      size_t m_serialNumber{ 0 };
      bool m_isFilled{ false };

      Item(const std::string& src) : m_itemName(src)
      {
      };
   };

   class CustomerOrder
   {
      std::string m_name{};
      std::string m_product{};
      size_t m_cntItem{};
      Item** m_lstItem{};
      static size_t m_widthField;
   public:
      CustomerOrder() = default;
      CustomerOrder(const std::string& s);
      CustomerOrder(const CustomerOrder& customerOrder);
      CustomerOrder& operator=(const CustomerOrder& customerOrder) = delete;
      CustomerOrder(CustomerOrder&& customerOrder) noexcept;
      CustomerOrder& operator=(CustomerOrder&& customerOrder) noexcept;
      ~CustomerOrder();
      bool isOrderFilled() const;
      bool isItemFilled(const std::string& itemName) const;
      void fillItem(Station& station, std::ostream& os);
      void display(std::ostream& ost)const;

   };
}

#endif

