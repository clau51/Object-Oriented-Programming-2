//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: Mar 12, 2023
//Section: NDD
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#include <string>
#include <iomanip>
#include <iostream>
#include <cctype> 
#include "Employee.h"
#include "Utilities.h"

using namespace std;
namespace sdds
{
   Employee::Employee(std::istream& istr)
   {
      if (istr)
      {
         //Name
         getline(istr, m_name, ',');
         trim(m_name);

         //Age
         string tempAge{};
         getAndCheckStringToInt(istr, tempAge, m_name, ',');
         m_age = tempAge;

         ////Doesn't work if you have letter at the end of a number
         //try
         //{
         //   int ageInt{};
         //   ageInt = stoi(tempAge);
         //   m_age = to_string(ageInt);
         //}
         //catch (const std::invalid_argument& e)
         //{
         //   std::cout << m_name;
         //   throw std::runtime_error("++Invalid record!");
         //}

         //ID
         string tempID = getAndCheckStringToID(istr, 'E', m_name, ',');
         m_id = tempID;
      }
   }
   std::string Employee::status() const
   {
      return "Employee";
   }
   std::string Employee::name() const
   {
      return m_name;
   }
   std::string Employee::id() const
   {
      return m_id;
   }
   std::string Employee::age() const
   {
      return m_age;
   }
   void Employee::display(std::ostream& out) const
   {
      out << "| ";
      out << left << setw(10) << Employee::status();
      out << "| ";
      out << left << setw(10) << m_id;
      out << "| ";
      out << left << setw(20) << m_name;
      out << " | ";
      out << left << setw(3) << m_age << " |";
   }
}
