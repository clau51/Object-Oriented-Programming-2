#ifndef SDDS_EMPLOYEE_H_
#define SDDS_EMPLOYEE_H_

#include <string>
#include "Person.h"
#include "Utilities.h"

namespace sdds
{
   class Employee : public Person
   {
      int m_records{};
      std::string m_name{};
      std::string m_age{};
      std::string m_id{};
      std::string& trim(std::string& s);
      char readChar(char delimiter, const char* validChars, std::istream& istr);

   public:
      //Employee() = default; //do i need? 
      Employee(std::istream& istr);
      std::string status()const override;
      std::string name()const override;
      std::string id()const override;
      std::string age()const override;
      void display(std::ostream& out) const;

   };
}

#endif

