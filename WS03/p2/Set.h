#ifndef SDDS_SET_H_
#define SDDS_SET_H_

#include <cmath>
#include "Collection.h"

namespace sdds
{
   template <typename T>
   class Set : public Collection<T, 100>
   {
      bool add(const T& item) override
      {
         bool added = false;
         for (unsigned int i = 0; i < size(); i++)
         {
            if (item == m_collection[i])
            {

            }
         }
      }

   };

   template<>
   bool Set<double>::add(const double& item)
   {
      for (unsigned int i = 0; i < size(); i++)
      {
         //if ()
      }
   }
}

#endif