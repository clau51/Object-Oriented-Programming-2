//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: January 21, 2023
//Section: NDD
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "ProteinDatabase.h"
#include <iostream>
#include <fstream>

using namespace std;
namespace sdds
{
   std::istream& ProteinDatabase::read(std::istream& istr)
   {
      size_t i{ 0 };
      int skip{ 0 };

      do
      {
         string line{};

         getline(istr, line);
         if (line[0] != '>')
         {
            m_proteinSeq[i] += line;
         }
         else
         {
            if (skip > 0 && i < m_noOfRecs)
            {
               i++;
            }
            skip++;
         }
      } while (istr.peek() != EOF);

      return istr;
   }

   ProteinDatabase::ProteinDatabase(const ProteinDatabase& proteinDatabase)
   {
      *this = proteinDatabase;
   }

   ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& proteinDatabase)
   {
      if (this != &proteinDatabase)
      {
         delete[] m_proteinSeq;
         m_proteinSeq = nullptr;

         m_noOfRecs = proteinDatabase.m_noOfRecs;
         if (proteinDatabase.m_proteinSeq)
         {
            m_proteinSeq = new string[proteinDatabase.m_noOfRecs];
            for (size_t i{ 0 }; i < proteinDatabase.m_noOfRecs; i++)
            {
               m_proteinSeq[i] = proteinDatabase.m_proteinSeq[i];
            }
         }
      }

      return *this;
   }

   ProteinDatabase::ProteinDatabase(ProteinDatabase&& proteinDatabase) noexcept
   {
      *this = move(proteinDatabase);
   }

   ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase&& proteinDatabase) noexcept
   {
      if (this != &proteinDatabase)
      {
         delete[] m_proteinSeq;
         m_proteinSeq = nullptr;

         m_noOfRecs = proteinDatabase.m_noOfRecs;
         proteinDatabase.m_noOfRecs = 0;

         m_proteinSeq = proteinDatabase.m_proteinSeq;
         proteinDatabase.m_proteinSeq = nullptr;
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
               m_noOfRecs++;
            }
         } while (file.peek() != EOF);

         m_proteinSeq = new string[m_noOfRecs];
         file.seekg(0);

         read(file);
      }
   }

   size_t ProteinDatabase::size() const
   {
      return m_noOfRecs;
   }

   std::string ProteinDatabase::operator[](size_t seq) const
   {
      string empty{};
      return seq < m_noOfRecs ? m_proteinSeq[seq] : empty;
   }

   ProteinDatabase:: ~ProteinDatabase()
   {
      delete[] m_proteinSeq;
   }
}

