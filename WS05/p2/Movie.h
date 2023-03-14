//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: Feb 13, 2023
//Section: NDD
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_MOVIE_H_
#define SDDS_MOVIE_H_

#include <string>
#include "SpellChecker.h"

namespace sdds
{
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
}

#endif

