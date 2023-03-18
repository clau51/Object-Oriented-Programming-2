#include <iostream>
#include <iomanip>
#include "College.h"

using namespace std;

namespace sdds
{
   College& College::operator+=(Person* thePerson)
   {
      if (thePerson) //need to check if person is valid (ie age might be invalid)
      {
         m_persons.push_back(thePerson);
      }
      return *this;
   }

   void College::display(std::ostream& out) const
   {
      for (int i = 0; i < 2; i++)
      {
         out << "------------------------------------------------------------------------------------------------------------------------" << endl;
         out << setw(120) << " Test # " << i + 1 << " Persons in the college!| " << endl;
         out << "-----------------------------------------" << endl;


         for (auto& x : m_persons)
         {
            x->display(out);
         }
      }
   }

   College::~College()
   {
      for (auto& x : m_persons)
      {
         delete x;
      }
   }


}