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
      size_t m_nextSerial{};
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

