//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: Feb 5, 2023
//Section: NDD
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_COLLECTION_H_
#define SDDS_COLLECTION_H_

#include <iostream>
#include <iomanip>
#include "Pair.h"

namespace sdds
{
   template<typename T, unsigned int CAPACITY>
   class Collection
   {
      unsigned int m_noOfElements{};
      static T m_dummy;
      T m_collection[CAPACITY]{}; 
   public:
      unsigned int size() const
      {
         return m_noOfElements;
      }

      std::ostream& display(std::ostream& ostr = std::cout) const
      {
         ostr << "----------------------" << std::endl;
         ostr << "| Collection Content |" << std::endl;
         ostr << "----------------------" << std::endl;

         for (unsigned i = 0; i < m_noOfElements; i++)
         {
            ostr << m_collection[i] << std::endl;
         }

         ostr << "----------------------" << std::endl;

         return ostr;
      }

      virtual bool add(const T& item)
      {
         bool added = false;
         if (m_noOfElements < CAPACITY)
         {
            m_collection[m_noOfElements] = item;
            m_noOfElements++;
            added = true;
         }
         return added;
      }

      T operator[](const unsigned int index) const
      {
         return index < m_noOfElements ? m_collection[index] : m_dummy;
      }

      ~Collection() = default;
   };

   template<typename T, unsigned int CAPACITY>
   T Collection<T, CAPACITY>::m_dummy{};

   template<>
   Pair Collection<Pair, 100>::m_dummy{ "No Key", "No Value" };


}

#endif

