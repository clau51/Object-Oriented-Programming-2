//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: Mar 12, 2023
//Section: NDD
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <string>
#include <iomanip>
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

      if (utils.getFieldWidth() > Station::m_widthField)
      {
         m_widthField = utils.getFieldWidth();
      }

      m_description = utils.extractToken(str, position, more);
      id_generator++;
      m_id = id_generator;
   }
   const std::string& Station::getItemName() const
   {
      return m_name;
   }
   size_t Station::getNextSerialNumber()
   {
      return m_serialNum++;
   }
   size_t Station::getQuantity() const
   {
      return m_numItems;
   }
   void Station::updateQuantity()
   {
      if (m_numItems > 0)
      {
         m_numItems--;
      }
   }
   void Station::display(std::ostream& ostr, bool full) const
   {
      ostr << setw(3) << setfill('0') << m_id << " | " << setfill(' ');
      ostr << setw(m_widthField) << left << m_name << "  | ";
      ostr << setw(6) << right << setfill('0') << m_serialNum << " | ";
      if (full)
      {
         ostr << setw(4) << setfill(' ') << m_numItems << " | ";
         ostr << m_description;
      }

      ostr << endl;
   }


}