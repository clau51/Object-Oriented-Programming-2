#ifndef SDDS_PROFESSOR_H_
#define SDDS_PROFESSOR_H_

#include <string>
#include "Employee.h"

namespace sdds
{
   class Professor : public Employee
   {
      std::string m_department{};

   public:
      Professor(std::istream& in);
      void display(std::ostream& out) const;
      std::string status() const;;
      std::string department() const;
   };
}

#endif

