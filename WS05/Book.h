#ifndef SDDS_BOOK_H_
#define SDDS_BOOK_H_

#include <string>

namespace sdds
{
   class Book
   {
      std::string m_author{};
      std::string m_title{};
      std::string m_country{};
      size_t m_year{};
      double m_price{};
      std::string m_description{};

   public:
      const std::string& title() const;
      const std::string& country() const;
      const size_t& year() const;
      double& price();
      Book() = default;
      Book(const std::string& strBook);
      std::string& trim(std::string& s);
      friend std::ostream& operator<<(std::ostream& ostr, const Book& book);
   };
}

#endif

