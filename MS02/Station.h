//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: Mar 12, 2023
//Section: NDD
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef SDDS_STATION_H_
#define SDDS_STATION_H_

#include <string>

namespace sdds
{
   class Station
   {
      int m_id{};
      std::string m_name{};
      std::string m_description{};
      size_t m_serialNum{};
      size_t m_numItems{};
      static size_t m_widthField;
      static size_t id_generator;

   public:
      Station(const std::string& str);
      const std::string& getItemName() const;
      size_t getNextSerialNumber();
      size_t getQuantity()const;
      void updateQuantity();
      void display(std::ostream& ostr, bool full) const;

   };

}

#endif

