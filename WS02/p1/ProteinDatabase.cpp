#include "ProteinDatabase.h"
#include <iostream>
#include <fstream>

using namespace std;
namespace sdds
{
   ProteinDatabase::ProteinDatabase(std::string name)
   {
      ifstream file(name);

      if (file)
      {
         string prefix;
         do
         {
            getline(file, prefix);
            if (prefix[0] == '>')
            {
               m_noOfSeq++;
            }
         } while (file.peek() != EOF);
         m_elements = new string[m_noOfSeq];

      }

      file.seekg(0);
      if (file)
      {
         string prefix;
         int i = 0;
         do
         {
            getline(file, prefix);
            if (prefix[0] == '>')
            {
               string* seq = new string;
               string line;
               bool ok;
               do
               {
                  ok = true;
                  getline(file, line);
                  if (line.length() == 60)
                  {
                     seq->append(line);
                  }
                  else
                  {
                     seq->append(line);
                     m_elements[i] = *seq;
                     i++;
                     ok = false;
                  }
               } while (ok);
                      
            }
         } while (file.peek() != EOF);
      }
      else
      {
         cout << "Invalid file..." << endl;
      }

   }
   size_t ProteinDatabase::size() const
   {
      return m_noOfSeq;
   }
   std::string ProteinDatabase::operator[](size_t seq)
   {
      string empty{};
      return m_noOfSeq == seq - 1 ? m_elements[seq] : empty;
   }
   ProteinDatabase::~ProteinDatabase()
   {
      delete m_elements;
   }
}