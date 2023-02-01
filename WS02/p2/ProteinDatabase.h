//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: January 21, 2023
//Section: NDD
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_PROTEINDATABASE_H_
#define SDDS_PROTEINDATABASE_H_
#include <string>
#include <iostream>

namespace sdds
{
   class ProteinDatabase
   {
      std::string* m_proteinSeq{};
      size_t m_noOfRecs{};
      std::istream& read(std::istream& istr = std::cin);

   public:
      ProteinDatabase() = default;
      ProteinDatabase(const ProteinDatabase& proteinDatabase);
      ProteinDatabase& operator=(const ProteinDatabase& proteinDatabase);
      ProteinDatabase(ProteinDatabase&& proteinDatabase)noexcept;
      ProteinDatabase& operator=(ProteinDatabase&& proteinDatabase)noexcept;
      ProteinDatabase(const std::string name);
      size_t size() const;
      std::string operator[](size_t seq) const;
      ~ProteinDatabase();
   };
}

#endif