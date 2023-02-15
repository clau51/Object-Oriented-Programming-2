//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: Feb 7, 2023
//Section: NDD
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "Child.h"

using namespace std;
namespace sdds
{
   //Receives an array of pointers
   Child::Child(std::string name, int age, const Toy* toys[], size_t count)
   {
      m_name = name;
      m_age = age; //validate?
      m_count = count; //validate?
      //Assigning m_toy with dynamic memory of Toy Pointers | * | * | * |
      m_arrPtr = new const Toy* [count]; //m_arrPtr is now pointing to an array of pointers
      for (size_t i = 0; i < count; i++)
      {
         m_arrPtr[i] = new Toy(*toys[i]);
      }
   }

   Child::Child(const Child& child)
   {
      *this = child;
   }

   Child& Child::operator=(const Child& child)
   {
      if (this != &child)
      {
         for (int i = 0; i < m_count; i++)
         {
            delete m_arrPtr[i];
            m_arrPtr[i] = nullptr;
         }
         delete[] m_arrPtr;
         m_arrPtr = nullptr;

         m_name = child.m_name;
         m_age = child.m_age;
         m_count = child.m_count;

         if (child.m_arrPtr)
         {
            m_arrPtr = new const Toy * [m_count];
            for (int i = 0; i < m_count; i++)
            {
               m_arrPtr[i] = new Toy(*child.m_arrPtr[i]);
            }
         }
      }
      return *this;
   }

   Child::Child(Child&& child)
   {
      *this = move(child);
   }

   Child& Child::operator=(Child&& child)
   {
      if (this != &child)
      {
         for (int i = 0; i < m_count; i++)
         {
             delete m_arrPtr[i];
         }
         delete[] m_arrPtr;
         m_arrPtr = nullptr;

         m_name = child.m_name;
         child.m_name = "";
         m_age = child.m_age;
         child.m_age = 0;
         m_count = child.m_count;
         child.m_count = 0;

         for (int i = 0; i < child.m_count; i++)
         {
            m_arrPtr[i] = child.m_arrPtr[i];
            child.m_arrPtr[i] = nullptr;
         }
         m_arrPtr = child.m_arrPtr;
         child.m_arrPtr = nullptr;
      }

      return *this;
   }

   Child::~Child()
   {
      for (int i = 0; i < m_count; i++)
      {
         delete m_arrPtr[i];
      }

      delete[] m_arrPtr;
   }
   std::ostream& operator<<(std::ostream& ostr, const Child& child)
   {
      static int CALL_CNT = 1;

      ostr << "--------------------------" << endl;
      ostr << "Child " << CALL_CNT << ": " << child.m_name << " " << child.m_age << " years old:" << endl;
      ostr << "--------------------------" << endl;

      if (child.m_count > 0)
      {
         for (int i = 0; i < child.m_count; i++)
         {
            ostr << *child.m_arrPtr[i];
         }
      }
      else
      {
         ostr << "This child has no toys!" << endl;
      }

      ostr << "--------------------------" << endl;
      CALL_CNT++;

      return ostr;
   }
}