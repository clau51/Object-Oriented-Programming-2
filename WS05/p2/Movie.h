#ifndef SDDS_MOVIE_H_
#define SDDS_MOVIE_H_

#include <string>
#include "SpellChecker.h"

class Movie
{
   std::string m_title{};
   size_t m_year{};
   std::string m_description{};
public:
   Movie() = default;
   const std::string& title() const;
   Movie(const std::string& strMovie);

   template<typename T>
   void fixSpelling(T& spellChecker)
   {
      spellChecker(m_title);
      spellChecker(m_description);
   };

   friend std::ostream& operator<<(std::ostream& ostr, const Movie& movie);
   std::string& trim(std::string& s);
};

#endif

