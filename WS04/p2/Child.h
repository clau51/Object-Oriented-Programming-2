#ifndef SDDS_CHILD_H_
#define SDDS_CHILD_H_

#include <string>
#include "Toy.h"

namespace sdds
{
   class Child
   {
      std::string name{};
      int age{};
      const Toy** toy{};
   public:
      Child(std::string name, int age, const Toy* toys[], size_t count)
   };
}

#endif

