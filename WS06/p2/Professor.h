//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: Mar 12, 2023
//Section: NDD
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.



#ifndef SDDS_PROFESSOR_H_
#define SDDS_PROFESSOR_H_

#include <string>
#include <iostream>
#include "Employee.h"

namespace sdds
{
   class Professor : public Employee
   {
      std::string m_department{};

   public:
      Professor(std::istream& in);
      void display(std::ostream& out) const override;
      std::string status() const override;
      std::string department() const;
   };
}

#endif

