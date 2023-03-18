//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: Mar 12, 2023
//Section: NDD
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.



#include <string>
#include <cctype> 
#include <iomanip>
#include <iostream>
#include "Student.h"
#include "Utilities.h"

using namespace std;
namespace sdds
{
   Student::Student(std::istream& istr)
   {
      if (istr)
      {
         //Name
         getline(istr, m_name, ',');
         trim(m_name);

         //Age
         string tempAge{};
         getAndCheckStringToInt(istr, tempAge, m_name, ',');
         m_age = tempAge;

         ////Doesn't work if you have letter at the end of a number
         //string tempAge{};
         //getline(istr, tempAge, ',');
         //trim(tempAge);
         //try
         //{
         //   int ageInt{};
         //   ageInt = stoi(tempAge);
         //   string ageString{};
         //   m_age = to_string(ageInt);
         //}
         //catch (const std::invalid_argument& e)
         //{
         //   throw std::invalid_argument(m_name + "++Invalid record!");
         //}

         string tempID = getAndCheckStringToID(istr, 'S', m_name, ',');
         m_id = tempID;

         //# Courses
         string tempCourse{};
         getAndCheckStringToInt(istr, tempCourse, m_name, ',');
         m_count = stoi(tempCourse);

         //Courses
         m_courses = new string[m_count];
         for (size_t i = 0; i < m_count; i++)
         {
            string tempCourse{};
            getline(istr, tempCourse, ',');
            trim(tempCourse);
            m_courses[i] = tempCourse;
         }
      }


   }
   std::string Student::status() const
   {
      return "Student";
   }
   std::string Student::name() const
   {
      return m_name;
   }
   std::string Student::age() const
   {
      return m_age;
   }
   std::string Student::id() const
   {
      return m_id;
   }
   void Student::display(std::ostream& out) const
   {
      out << "| ";
      out << left << setw(10) << status();
      out << "| ";
      out << left << setw(10) << id();
      out << "| ";
      out << left << setw(20) << name();
      out << " | ";
      out << left << setw(3) << age() << " |";
      for (size_t i = 0; i < m_count; i++)
      {
         if (i == m_count - 1)
         {
            out << m_courses[i];
         }
         else
         {
            out << m_courses[i] << ", ";
         }
      }
   }

   Student::~Student()
   {
      delete[] m_courses;
   }
}