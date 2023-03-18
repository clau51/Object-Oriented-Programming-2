//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: Mar 12, 2023
//Section: NDD
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.



#ifndef SDDS_UTILIES_H_
#define SDDS_UTILIES_H_

#include <string>
#include <iostream>
#include "Person.h"
namespace sdds
{
   Person* buildInstance(std::istream& in);
   std::string& trim(std::string& s);
   std::string& getAndCheckStringToInt(std::istream& istr, std::string& s, const std::string& name, char delimiter);
   std::string getAndCheckStringToID(std::istream& istr, char letter, const std::string& name, char delimiter); 
}
#endif
