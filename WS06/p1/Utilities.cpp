#include <sstream>
#include "Utilities.h"
#include "Employee.h"

using namespace std;
namespace sdds
{
   Person* buildInstance(std::istream& in)
   {
      string tempString{};
      string tag{};
      getline(in, tag, ',');
      size_t first = tag.find_first_not_of(' ');
      
      getline(in, tempString);
      stringstream ss(tempString);


      Employee* employee{};
      // check here cause it caused errors earlier (run thru code w/o if)
      if (first != std::string::npos)
      {
         if (tag[first] == 'E' || tag[first] == 'e')
         {
            //// Put the tempString back into the istream
            //for (int i = tempString.length() - 1; i >= first; i--)
            //{
            //   in.putback(tempString[i]);
            //}
            //in.putback('\n');

            employee = new Employee(ss);
         }
      }
      return employee;
   }
}