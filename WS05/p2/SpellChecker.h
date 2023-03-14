//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: Feb 13, 2023
//Section: NDD
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef SDDS_SPELLCHECKER_H_
#define SDDS_SPELLCHECKER_H_

#include <string>

namespace sdds
{
   class SpellChecker
   {
      std::string m_badWords[6]{};
      std::string m_goodWords[6]{};
      int m_replaceCount[6]{};
      size_t m_vocabCount{};

   public:
      SpellChecker(const char* filename);
      void operator()(std::string& text);
      void showStatistics(std::ostream& out)const;
   };
}

#endif