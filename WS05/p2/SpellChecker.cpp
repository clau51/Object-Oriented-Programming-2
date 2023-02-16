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
            do
            {
               file >> m_badWords[m_vocabCount];
               file >> m_goodWords[m_vocabCount];
               m_vocabCount++;

               //NEED TO FIX, EXTRA LINE GETTING STORED
            } while (file.peek() != EOF);
         }
         else
         {
            const char* msg = "Bad file name!";
            throw msg;
         }

      } //else
   }
   void SpellChecker::operator()(std::string& text)
   {
      for (int i = 0; i < m_vocabCount; i++)
      {
         //NEEDS TO FIX TO SEARCH MULTIPLE WORDS IN SAME SENTENCE

         int begIndex = text.find(m_badWords[i]);
         if (begIndex >= 0)
         {
            text.replace(begIndex, m_badWords[i].length(), m_goodWords[i]);
            m_replaceCount[i]++;
         }
      }
   }

   void SpellChecker::showStatistics(std::ostream& out) const
   {
      out << "Spellchecker Statistics" << endl;
      for (int i = 0; i < m_vocabCount; i++)
      {
         out << setw(15) << m_badWords[i] << ": " << m_replaceCount[i] << " replacements\n";
      }
   }

}