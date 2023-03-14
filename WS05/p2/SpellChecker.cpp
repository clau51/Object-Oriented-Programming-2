//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: Feb 13, 2023
//Section: NDD
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "SpellChecker.h"

using namespace std;
namespace sdds
{
   SpellChecker::SpellChecker(const char* filename)
   {
      if (filename[0])
      {
         ifstream file(filename);

         if (file)
         {
            string tempBad{};
            string tempGood{};
            do
            {
               file >> tempBad;
               file >> tempGood;
               if (tempBad.find_first_not_of(' ') != std::string::npos &&
                  tempGood.find_first_not_of(' ') != std::string::npos)
               {
                  m_badWords[m_vocabCount] = tempBad;
                  m_goodWords[m_vocabCount] = tempGood;
                  m_vocabCount++;
                  tempBad = ' ';
                  tempGood = ' ';
               }

            } while (file.peek() != EOF);
         }
         else
         {
            const char* msg = "Bad file name!";
            throw msg;
         }
      } 
   }

   void SpellChecker::operator()(std::string& text)
   {
      for (size_t i = 0; i < m_vocabCount; i++)
      {
         size_t begIndex = text.find(m_badWords[i]);
         while (begIndex != std::string::npos)
         {
            text.replace(begIndex, m_badWords[i].length(), m_goodWords[i]);
            m_replaceCount[i]++;
            begIndex = text.find(m_badWords[i]);
         }
      }
   }

   void SpellChecker::showStatistics(std::ostream& out) const
   {
      out << "Spellchecker Statistics" << endl;
      for (size_t i = 0; i < m_vocabCount; i++)
      {
         out << setw(15) << m_badWords[i] << ": " << m_replaceCount[i] << " replacements\n";
      }
   }

}