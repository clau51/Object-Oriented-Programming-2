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

//Toy*
// [ m_arrOfPtrs[0] , m_arrOfPtrs[1]] 
//0               1
//
////m_arrOfPtrs[0] a toy pointer
//Toy toy1;
//
//m_arrOfPtrs[0] = new Toy(toy1)

#endif

