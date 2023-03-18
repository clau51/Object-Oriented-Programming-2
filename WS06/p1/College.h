#ifndef SDDS_COLLEGE_H_
#define SDDS_COLLEGE_H_

#include <vector>
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

      ~College();
   };
}

#endif

