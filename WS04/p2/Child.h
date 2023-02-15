//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: Feb 7, 2023
//Section: NDD
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_CHILD_H_
#define SDDS_CHILD_H_

#include <string>
#include "Toy.h"

namespace sdds
{
   class Child
   {
      std::string m_name{};
      int m_age{};
      const Toy** m_arrPtr{};
      int m_count{};
   public:
      Child(std::string name, int age, const Toy* toys[], size_t count);
      Child(const Child& child);
      Child& operator=(const Child& child);
      Child(Child&& child);
      Child& operator=(Child&& child);
      ~Child();
      friend std::ostream& operator<<(std::ostream& ostr, const Child& child);
   };
}

#endif

