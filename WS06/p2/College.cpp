//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: Mar 12, 2023
//Section: NDD
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.



#include <iostream>
#include <iomanip>
#include <vector>
#include "Person.h"
#include "College.h"

using namespace std;

namespace sdds
{
   College& College::operator+=(Person* thePerson)
   {
      m_persons.push_back(thePerson);

      return *this;
   }

   void College::display(std::ostream& out) const
   {
      //Test 1
      std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
      std::cout << "|                                        Test #1 Persons in the college!                                               |\n";
      std::cout << "------------------------------------------------------------------------------------------------------------------------\n";

      for (auto i = m_persons.begin(); i != m_persons.end(); i++)
      {
         (*i)->display(out);
         out << endl;
      }

      //Test 2
      std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
      std::cout << "|                                        Test #2 Persons in the college!                                               |\n";
      std::cout << "------------------------------------------------------------------------------------------------------------------------\n";


      for (auto i = m_persons.begin(); i != m_persons.end(); i++)
      {
         out << "| ";
         out << left << setw(10) << (*i)->status();
         out << "| ";
         out << left << setw(10) << (*i)->id();
         out << "| ";
         out << left << setw(20) << (*i)->name();
         out << " | ";
         out << left << setw(3) << (*i)->age() << " |" << endl;
      }
      std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
   }

   College::~College()
   {
      for (auto i = m_persons.begin(); i != m_persons.end(); i++)
      {
         delete *i;
      }
   }


}