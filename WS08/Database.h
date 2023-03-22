#ifndef SDDS_DATABASE_H_
#define SDDS_DATABASE_H_
#include <memory>
#include <string>
namespace sdds
{
   const int MAX_CAPACITY = 20;

   enum class Err_Status
   {
      Err_Success,
      Err_NotFound,
      Err_OutOfMemory,
   };

   class Database
   {
      size_t m_entries{};
      std::string m_key[MAX_CAPACITY]{};
      std::string m_value[MAX_CAPACITY]{};
      std::string m_filename{};
      static std::shared_ptr<Database> instancePtr;
      Database(const std::string& filename);
      std::string& trim(std::string& s)
      {
         int first = s.find_first_not_of(' ');
         int last = s.find_last_not_of(' ');

         s.erase(0, first);
         s.erase(last + 1 - first);
         return s;
      }


      //static Database* database; //store address of the one and only instance of type Database
   public:
      static std::shared_ptr<Database> getInstance(const std::string& filename);
      Err_Status GetValue(const std::string& key, std::string& value);
      Err_Status SetValue(const std::string& key, const std::string& value);
      ~Database();
   };

   //Database* Database::database{};


}

#endif

