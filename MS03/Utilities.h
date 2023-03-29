//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: Mar 18, 2023
//Section: NDD
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef SDDS_UTILITIES_H_
#define SDDS_UTILITIES_H_

#include <string>
namespace sdds
{
   class Utilities
   {
      size_t m_widthField = 1;
      static char m_delim; //class variable
   public:
      void setFieldWidth(size_t newWidth);
      size_t getFieldWidth()const;
      std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
      static void setDelimiter(char newDelimiter);
      static char getDelimiter();
      std::string& trim(std::string& s);
   };

}

#endif

