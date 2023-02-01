#ifndef SDDS_COLLECTION_H_
#define SDDS_COLLECTION_H_

#include <iostream>
#include <iomanip>
#include "Pair.h"

namespace sdds
{
   template<typename T, unsigned int capacity>
   class Collection
   {
      unsigned int m_noOfElements{};
      T m_dummy{}; //Pair m_dummy - call constructor & initialize to 0
   protected:
      T m_collection[capacity]{}; //Pair m_collection[10]
   public:
      unsigned int size() const
      {
         return m_noOfElements;
      }

      void display(std::ostream& ostr = std::cout) const
      {
         ostr << "----------------------" << std::endl;
         ostr << "| Collection Content |" << std::endl;
         ostr << "----------------------" << std::endl;

         for (unsigned i = 0; i < m_noOfElements; i++)
         {
            ostr << m_collection[i] << std::endl;
         }

         ostr << "----------------------" << std::endl;
      }

      virtual bool add(const T& item)
      {
         bool added = false;
         if (m_noOfElements < capacity)
         {
            m_collection[m_noOfElements] = item;
            m_noOfElements++;
            added = true;
         }
         return added;
      }

      T operator[](unsigned int index) const
      {
         return index < m_noOfElements ? m_collection[index] : m_dummy;
      }

      ~Collection() = default;
   };

   template<>
   class Collection<Pair, 100>
   {
      Pair m_dummy{ "No key", "No Value" };
   };

   //template<typename T, unsigned int capacity>
   //unsigned int Collection<typename T, capacity>::m_noOfElements;

}

#endif

