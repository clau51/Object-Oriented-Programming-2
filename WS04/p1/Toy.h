#ifndef SDDS_TOY_H_
#define SDDS_TOY_H_

#include <string>
#include "Toy.h"

namespace sdds
{
   class Toy
   {
      unsigned int m_orderID{};
      std::string m_toyName{};
      int m_noOfToys{};
      double m_price{};
      double m_tax = 0.13;
      std::string& trim(std::string& s);

   public:
      Toy() = default;
      void update(int numItems);
      Toy(const std::string& toy);
      friend std::ostream& operator<<(std::ostream& ostr, const Toy& toy);
   };

}

#endif

//#ID:Name:NUM:PRICE
//
////std::string a = "0123456789abcdefghij"
//std::string sub1 = a.substr(10); // abcdefghij
//std::string sub2 = a.substr(5, 3); //567
//std::string sub4 = a.substr(a.size() - 3, 50); //hij
//
////std::string const s = "This is a string";
//n = s.find("is"); //2 //substr(2) = "is is a string"
//n = s.find("is", 5); //5 //substr(5) = "is a string"
//n = s.find('a'); //8 //substr(8) = "a string"
//
////std::string s = "This Is An Example";
//s.erase(7, 3); //This Is Example
//s.erase(std::find(s.begin(), s.end(), ' ')); //ThisIs Example
//s.erase(s.find(' ')); //ThisIs


