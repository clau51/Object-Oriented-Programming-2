#include <iostream>
#include <iomanip>
#include "Book.h"

using namespace std;
namespace sdds
{
   const std::string& Book::title() const
   {
      return m_title;
   }
   const std::string& Book::country() const
   {
      return m_country;
   }
   const size_t& Book::year() const
   {
      return m_year;
   }
   double& Book::price()
   {
      return m_price;
   }
   Book::Book(const std::string& strBook)
   {
      string temp = strBook;

      //Author
      int colonIndex = temp.find(',');
      m_author = temp.substr(0, colonIndex);
      trim(m_author);
      temp.erase(0, colonIndex + 1);

      //Title
      colonIndex = temp.find(',');
      m_title = temp.substr(0, colonIndex);
      trim(m_title);
      temp.erase(0, colonIndex + 1);

      //Country
      colonIndex = temp.find(',');
      m_country = temp.substr(0, colonIndex);
      trim(m_country);
      temp.erase(0, colonIndex + 1);

      //Price
      colonIndex = temp.find(',');
      m_price = stod(temp);
      temp.erase(0, colonIndex + 1);

      //Year
      colonIndex = temp.find(',');
      m_year = stoul(temp);
      temp.erase(0, colonIndex + 1);

      //Description
      m_description = temp.substr(0);
      trim(m_description);
   }

   std::string& Book::trim(std::string& s)
   {
      int first = s.find_first_not_of(' ');
      int last = s.find_last_not_of(' ');
      s.erase(0, first);
      s.erase(last + 1 - first);
      return s;
   }
   std::ostream& operator<<(std::ostream& ostr, const Book& book)
   {
      ostr << setw(20) << book.m_author << "|";
      ostr << setw(22) << book.m_title << "|";
      ostr << setw(5) << book.m_country << "|";
      ostr << setw(4) << book.m_year << "|";
      ostr << setw(6) << fixed << setprecision(2) << book.m_price << "|";
      ostr << book.m_description;

      return ostr;
   }
}