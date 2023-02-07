//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: Feb 5, 2023
//Section: NDD
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_SET_H_
#define SDDS_SET_H_

#include <cmath>
#include "Collection.h"

namespace sdds
{
   template <typename T>
   class Set : public Collection<T, 100>
   {
   public:
      bool add(const T& item) override
      {
         bool added{};

         if (Collection<T, 100>::size() == 0u) 
         {
            Collection<T, 100>::add(item);
            added = true;
         }
         else
         {
            bool exists{};
            for (unsigned int i = 0; i < Collection<T, 100>::size() && !exists; i++)
            {
               if (item == (*this)[i])
               {
                  exists = true;
               }
            }

            if (!exists)
            {
               Collection<T, 100>::add(item);
               added = true;
            }
         }

         return added;
      }

   };

   template<>
   bool Set<double>::add(const double& item)
   {
      bool added{};

      if (Collection<double, 100>::size() == 0u)
      {
         Collection<double, 100>::add(item);
         added = true;
      }
      else
      {
         bool exists{};
         for (unsigned int i = 0; i < Collection<double, 100>::size() && !exists; i++)
         {
            if (std::fabs(item - (*this)[i]) <= 0.01)
            {
               exists = true;
            }
         }

         if (!exists)
         {
            Collection<double, 100>::add(item);
            added = true;
         }
      }

      return added;
   }
}

#endif