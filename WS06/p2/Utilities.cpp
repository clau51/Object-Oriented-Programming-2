//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: Mar 12, 2023
//Section: NDD
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.



#include <sstream>
#include <string>
#include <iostream>
#include "Person.h"
#include "Utilities.h"
#include "Employee.h"
#include "Student.h"
#include "Professor.h"

using namespace std;
namespace sdds
{
   Person* buildInstance(std::istream& in)
   {
      string tag{};
      getline(in, tag, ',');

      size_t first = tag.find_first_not_of(' ');

      string tempString{};
      getline(in, tempString);
      stringstream ss(tempString);

      Person* person{};
      if (first != std::string::npos)
      {
         if (toupper(tag[first]) == 'E')
         {
            person = new Employee(ss);
         }
         else if (toupper(tag[first]) == 'S')
         {
            person = new Student(ss);
         }
         else if (toupper(tag[first]) == 'P')
         {
            person = new Professor(ss);
         }
      }
      return person;
   }

   std::string& trim(std::string& s)
   {
      int first = s.find_first_not_of(' ');
      int last = s.find_last_not_of(' ');
      if (first != -1 && last != -1)
      {
         s.erase(0, first);
         s.erase(last + 1 - first);
      }
      else
      {
         throw out_of_range("Out of range");
      }
      return s;

   }

   std::string& getAndCheckStringToInt(std::istream& istr, std::string& s, const std::string& name, char delimiter)
   {
      getline(istr, s, delimiter);
      trim(s);
      bool containsNonDigit{};
      for (size_t i = 0; i < s.length() && !containsNonDigit; i++)
      {
         if (!isdigit(s[i]))
         {
            containsNonDigit = true;
            throw invalid_argument(name + "++Invalid record!");
         }
      }

      return s;
   }

   std::string getAndCheckStringToID(std::istream& istr, char letter, const std::string& name, char delimiter)
   {
      string tempID{};
      getline(istr, tempID, ',');
      trim(tempID);
      if (tempID[0] != letter)
      {
         throw invalid_argument(name + "++Invalid record!");
      }

      return tempID;
   }

   
}