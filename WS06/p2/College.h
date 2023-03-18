//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: Mar 12, 2023
//Section: NDD
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.



#ifndef SDDS_COLLEGE_H_
#define SDDS_COLLEGE_H_

#include <vector>
#include <list>
#include <iostream>
#include "Person.h"

namespace sdds
{
   class College
   {
      std::vector<Person*> m_persons{};

   public:
      College() = default;
      College(const College& college) = delete;
      College& operator=(const College& college) = delete;
      College& operator +=(Person* thePerson);
      void display(std::ostream& out) const;

      template <typename T>
      void select(const T& test, std::list<const Person*>& persons) //const
      {
         for (const auto& person : m_persons)
         {
            if (test(person))
            {
               persons.push_back(person);
            }
         }
      }
      virtual ~College();
   };
}

#endif

