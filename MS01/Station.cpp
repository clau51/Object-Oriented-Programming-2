#include <string>
#include "Station.h"
#include "Utilities.h"

using namespace std;
namespace sdds
{
   size_t Station::id_generator{};
   size_t Station::m_widthField = 0;

   Station::Station(const std::string& str)
   {
       Utilities utils{};
       size_t position{};
       bool more{};
       m_name = utils.extractToken(str, position, more);
       m_serialNum = stoul(utils.extractToken(str, position, more));
       m_numItems = stoi(utils.extractToken(str, position, more));

       if (utils.getFieldWidth() > Station::m_widthField) {
           m_widthField = utils.getFieldWidth();
       }

       m_description = utils.extractToken(str, position, more);
   }
   const std::string& Station::getItemName() const
   {
       return m_name;
   }
   size_t Station::getNextSerialNumber()
   {
      return m_next
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