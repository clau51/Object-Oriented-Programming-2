#ifndef SDDS_PROTEINDATABASE_H_
#define SDDS_PROTEINDATABASE_H_
#include <string>

namespace sdds
{
   class ProteinDatabase
   {
      std::string* m_elements{};
      size_t m_noOfSeq{};

   public:
      ProteinDatabase() = default;
      ProteinDatabase(std::string name);
      size_t size() const;
      std::string operator[](size_t seq);
      ~ProteinDatabase();

   };
}

#endif