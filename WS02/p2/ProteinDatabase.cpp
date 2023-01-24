#include "ProteinDatabase.h"
#include <iostream>
#include <fstream>

using namespace std;
namespace sdds
{
   ProteinDatabase::ProteinDatabase(const ProteinDatabase& proteinDatabase)
   {
      *this = proteinDatabase;
   }

   ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& proteinDatabase)
   {
      if (this != &proteinDatabase)
      {
         delete[] m_elements;
         m_elements = nullptr;

         if (proteinDatabase.m_elements)
         {
            m_elements = new string[proteinDatabase.m_noOfSeq];
            for (int i = 0; i < static_cast<int>(proteinDatabase.m_noOfSeq); i++)
            {
               m_elements[i] = proteinDatabase.m_elements[i];
            }
         }

         m_noOfSeq = proteinDatabase.m_noOfSeq;
      }

      return *this;
   }

   ProteinDatabase::ProteinDatabase(ProteinDatabase&& proteinDatabase)
   {
      *this = move(proteinDatabase);
   }

   ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase&& proteinDatabase)
   {
      if (this != &proteinDatabase)
      {
         delete[] m_elements;

         m_elements = proteinDatabase.m_elements;
         proteinDatabase.m_elements = nullptr;
         m_noOfSeq = proteinDatabase.m_noOfSeq;
         proteinDatabase.m_noOfSeq = 0;
      }
      return *this;
   }

   ProteinDatabase::ProteinDatabase(std::string name)
   {
      ifstream file(name);

      if (file)
      {
         string prefix{};
         do
         {
            getline(file, prefix);
            if (prefix[0] == '>')
            {
               m_noOfSeq++;
            }
         } while (file.peek() != EOF);

         m_elements = new string[m_noOfSeq];
         file.seekg(0);

         do
         {
            static int i{ 0 };
            string line{};
            static string seq{};
            getline(file, line);
            if (line[0] != '>')
            {
               seq.append(line);
               if (line.length() != 60 || file.peek() == '>')
               {
                  m_elements[i] = seq;
                  i++;
                  seq = "";
               }
            }
         } while (file.peek() != EOF);
      }
   }

   size_t ProteinDatabase::size() const
   {
      return m_noOfSeq;
   }
   std::string ProteinDatabase::operator[](size_t seq)
   {
      string empty{};
      return seq < m_noOfSeq ? m_elements[seq] : empty;
   }
   ProteinDatabase::~ProteinDatabase()
   {
      delete[] m_elements;
   }
}

