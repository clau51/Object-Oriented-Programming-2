#include <string>
#include <iomanip>
#include <cstring>
#include "Employee.h"

using namespace std;
namespace sdds
{
   std::string& Employee::trim(std::string& s)
   {
      int first = s.find_first_not_of(' ');
      int last = s.find_last_not_of(' ');
      s.erase(0, first);
      s.erase(last + 1 - first);
      return s;
   }

   char Employee::readChar(char delimiter, const char* validChars, istream& istr)
   {
      char input;
      char del;

      istr >> input;
      del = istr.get();
      if (del != delimiter)
      {
         istr.ignore(1000, delimiter);
         istr.setstate(ios::failbit);
      }
      else
      {
         bool isFound = false;
         for (size_t i = 0; i < strlen(validChars) && !isFound; i++)
         {
            if (input == validChars[i])
            {
               isFound = true;
            }
         }

         if (!isFound)
         {
            istr.setstate(ios::failbit);
         }
      }
      return input;
   }


   Employee::Employee(std::istream& istr)
   {
      if (istr)
      {
         //char tempTag{};
         //tempTag = readChar(',', "eE", istr);
         //if (istr)
         //{
         //   m_tag = tempTag;
         //}
         string tempName{};
         getline(istr, tempName, ',');
         trim(tempName);
         m_name = tempName;

         string tempAge{};
         getline(istr, tempAge, ',');
         trim(tempAge);
         try
         {
            int ageInt{};
            ageInt = stoi(tempAge);
            m_age = to_string(ageInt);
         }
         catch (const std::invalid_argument& e)
         {
            m_records++; //need?
            throw std::runtime_error("++Invalid record!");
         }

         string tempID{};
         getline(istr, tempID);
         trim(tempID);
         if (tempID[0] == 'E')
         {
            m_id = tempID;
         }
         else
         {
            m_records++;
            std::cout << m_name;
            throw std::runtime_error("++Invalid record!");
         }

         //if (istr)
         //{
         //   std::string tempString{};
         //   getline(istr, tempString);

         //   int colonIndex = tempString.find(',');
         //   m_name = tempString.substr(0, colonIndex);
         //   trim(m_name);
         //   tempString.erase(0, colonIndex + 1);

         //   std::string tempAge{};
         //   colonIndex = tempString.find(',');
         //   tempAge = tempString.substr(0, colonIndex);
         //   trim(tempAge);
         //   try
         //   {
         //      int ageInt{};
         //      ageInt = stoi(tempAge);
         //      m_age = to_string(ageInt);
         //   }
         //   catch (const std::invalid_argument& e)
         //   {
         //      m_records++; //need?
         //      throw std::runtime_error("++Invalid record!");
         //   }
         //   tempString.erase(0, colonIndex + 1);


         //   //FIX ?? end has a new line, not a comma
         //   string tempID{};
         //   colonIndex = tempString.find(',');
         //   if (colonIndex == std::string::npos)
         //   {
         //      trim(tempString);
         //      if (tempString[0] == 'E')
         //      {
         //         m_id = tempString;
         //      }
         //      else
         //      {
         //         m_records++;
         //         std::cout << m_name;
         //         throw std::runtime_error("++Invalid record!");
         //      }
         //   }
         //   else
         //   {
         //      tempID = tempString.substr(0, colonIndex);
         //      trim(tempID);
         //      if (tempID[0] == 'E')
         //      {
         //         m_id = tempID;
         //      }
         //      else
         //      {
         //         m_records++;
         //         std::cout << m_name;
         //         throw std::runtime_error("++Invalid record!");
         //      }
         //      tempString.erase(0, colonIndex + 1);
         //   }
         //}
      }
   }
   std::string Employee::status() const
   {
      return "Employee";
   }
   std::string Employee::name() const
   {
      return m_name;
   }
   std::string Employee::id() const
   {
      return m_id;
   }
   std::string Employee::age() const
   {
      return m_age;
   }
   void Employee::display(std::ostream& out) const
   {
      out << "|";
      out << setw(10) << status();
      out << "|";
      out << setw(10) << m_id; //could use querys instead
      out << "|";
      out << setw(20) << m_name;
      out << "|";
      out << setw(3) << m_age << "|" << endl;

   }
}
