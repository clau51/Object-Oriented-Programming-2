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