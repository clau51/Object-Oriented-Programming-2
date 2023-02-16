#include <string>
#include <iomanip>
#include "Movie.h"

using namespace std;
const std::string& Movie::title() const
{
   return m_title;
}

Movie::Movie(const std::string& strMovie)
{
   string temp = strMovie;

   //Title
   int colonIndex = temp.find(',');
   m_title = temp.substr(0, colonIndex);
   trim(m_title);
   temp.erase(0, colonIndex + 1);

   //Year
   colonIndex = temp.find(',');
   m_year = stoul(temp);
   temp.erase(0, colonIndex + 1);

   //Description
   m_description = temp.substr(0);
   trim(m_description);
}

std::ostream& operator<<(std::ostream& ostr, const Movie& movie)
{
   ostr << setw(40) << movie.m_title << "|";
   ostr << setw(4) << movie.m_year << "|";
   ostr << movie.m_description << endl;

   return ostr;
}

std::string& Movie::trim(std::string& s)
{
   int first = s.find_first_not_of(' ');
   int last = s.find_last_not_of(' ');
   s.erase(0, first);
   s.erase(last + 1 - first);
   return s;
}

