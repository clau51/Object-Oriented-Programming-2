#include <string>
#include "Station.h"

using namespace std;
namespace sdds
{
   size_t Station::id_generator{};
   size_t Station::m_widthField = 0;

   Station::Station(const std::string& str)
   {

   }
   const std::string& Station::getItemName() const
   {
      return string();
   }
   size_t Station::getNextSerialNumber()
   {
      return size_t();
   }
   size_t Station::getQuantity() const
   {
      return size_t();
   }
   void Station::updateQuantity()
   {
   }
   void Station::display(std::ostream& ostr, bool full) const
   {
   }


}