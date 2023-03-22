#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include "Database.h"
using namespace std;

namespace sdds
{
   extern const int MAX_CAPACITY;

   std::shared_ptr<Database> Database::instancePtr{};

   Database::Database(const string& filename)
   {
      cout << std::hex;
      cout << "[" << this << "] Database(const std::string&)" << endl;

      ifstream file(filename);
      if (file)
      {
         m_filename = filename;
         string tempString{};
         string tempKey{};
         string tempValue{};
         size_t pos{};

         while (getline(file, tempString))
         {
            pos = tempString.find_first_of(' ');
            tempKey = tempString.substr(0, pos);
            trim(tempKey);
            tempValue = tempString.substr(pos + 1, tempString.length());
            trim(tempValue);

            replace(tempKey.begin(), tempKey.end(), '_', ' ');

            m_key[m_entries] = tempKey;
            m_value[m_entries] = tempValue;
            m_entries++;
         }
      }

   }

   shared_ptr<Database> Database::getInstance(const std::string& filename)
   {

      return instancePtr ? instancePtr : instancePtr = shared_ptr<Database>(new Database(filename));
   }
   Err_Status Database::GetValue(const std::string& key, std::string& value)
   {
      bool ok{};
      auto found = find(m_key->begin(), m_key->end(), key);
      if (found != m_key->end()) 
      {
         ok = true;
         value = m_value[*found];
      }

      //bool ok{};
      //for (size_t i = 0; i < m_entries && !ok; i++)
      //{
      //   if (m_key[i] == key)
      //   {
      //      value = m_value[m_entries];
      //      ok = true;
      //   }
      //}
      return ok ? Err_Status::Err_Success : Err_Status::Err_NotFound;
   }

   Err_Status Database::SetValue(const std::string& key, const std::string& value)
   {
      bool added{};
      if (m_entries < MAX_CAPACITY)
      {
         m_key[m_entries] = key;
         m_value[m_entries] = value;
         added = true;
      }
      return added ? Err_Status::Err_Success : Err_Status::Err_OutOfMemory;
   }

   Database::~Database()
   {
      for (size_t i = 0; i < m_entries; i++)
      {
         cout << m_key[i] << " earned " << m_value[i] << endl;
      }

      cout << std::hex;
      cout << "[" << instancePtr << "] ~Database()" << endl; //or this?


      ofstream file(m_filename + ".bkp.txt");
      for (size_t i = 0; i < m_entries; i++)
      {
         file << setw(25) << left << m_key[i] << "-> " << m_value[i] << endl;
      }

   }

}
