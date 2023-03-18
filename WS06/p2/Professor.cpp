//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: Mar 12, 2023
//Section: NDD
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.



#include <string>
#include <iostream>
#include "Professor.h"
#include "Utilities.h"

using namespace std;
namespace sdds
{
   sdds::Professor::Professor(std::istream& in) : Employee(in)
   {
      string tempDepartment{};
      getline(in, tempDepartment);
      trim(tempDepartment);
      m_department = tempDepartment;
   }

   void Professor::display(std::ostream& out) const
   {
      Employee::display(out);
      out << department();
      out << "| ";
      out << Professor::status();
   }

   std::string Professor::status() const
   {
      return "Professor";
   }

   std::string Professor::department() const
   {
      return m_department;
   }
}
