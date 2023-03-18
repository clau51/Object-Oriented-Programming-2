//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: Mar 12, 2023
//Section: NDD
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef SDDS_STUDENT_H_
#define SDDS_STUDENT_H_

#include <string>
#include <iostream>
#include "Person.h"

namespace sdds
{
   class Student : public Person
   {
      std::string m_name{};
      std::string m_age{};
      std::string m_id{};
      std::string* m_courses{};
      size_t m_count{};
      std::string age() const override;
      std::string id() const override;

   public:
      Student(std::istream& istr);
      Student(const Student& student) = delete;
      Student& operator=(const Student& student) = delete;
      std::string status() const override;
      std::string name() const override;
      void display(std::ostream& out) const override;
      virtual ~Student(); 
   };
}

#endif

