//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: Feb 7, 2023
//Section: NDD
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "ConfirmOrder.h"

using namespace std;
namespace sdds
{
   ConfirmOrder& ConfirmOrder::operator+=(const Toy& toy)
   {
      bool isExist{};
      const Toy** temp{};

      for (int i = 0; i < m_count && !isExist; i++)
      {
         if (m_arrPtr[i] == &toy)
         {
            isExist = true;
         }
      }

      if (!isExist)
      {
         temp = new const Toy* [m_count + 1]; //create a new dynamically allocated array of Toy pointers
         for (int i = 0; i < m_count; i++)
         {
            temp[i] = m_arrPtr[i];
         }
         temp[m_count++] = &toy;

         delete[] m_arrPtr;
         m_arrPtr = temp;
      }

      return *this;
   }
   ConfirmOrder& ConfirmOrder::operator-=(const Toy& toy)
   {
      bool isExist{};
      const Toy** temp;
      for (int i = 0; i < m_count && !isExist; i++)
      {
         if (m_arrPtr[i] == &toy)
         {
            isExist = true;
            m_arrPtr[i] = nullptr;
         }
      }

      int counter{};
      if (isExist)
      {
         temp = new const Toy * [m_count - 1];
         for (int i = 0; i < m_count; i++)
         {
            if (m_arrPtr[i] != nullptr)
            {
               temp[counter++] = m_arrPtr[i];
            }
         }
         m_count--;
         delete[] m_arrPtr;
         m_arrPtr = temp;
      }
      return *this;
   }
   ConfirmOrder::ConfirmOrder(const ConfirmOrder& confirmOrder)
   {
      *this = confirmOrder;
   }

   ConfirmOrder& ConfirmOrder::operator=(const ConfirmOrder& confirmOrder)
   {
      if (this != &confirmOrder)
      {
         delete[] m_arrPtr;
         m_arrPtr = nullptr;
         
         m_count = confirmOrder.m_count;

         if (confirmOrder.m_arrPtr)
         {
            m_arrPtr = new const Toy * [m_count];
            for (int i = 0; i < m_count; i++)
            {
               m_arrPtr[i] = confirmOrder.m_arrPtr[i];
            }
         }
      }

      return *this;
   }

   ConfirmOrder::ConfirmOrder(ConfirmOrder&& confirmOrder)noexcept
   {
      *this = move(confirmOrder);
   }

   ConfirmOrder& ConfirmOrder::operator=(ConfirmOrder&& confirmOrder)noexcept
   {
      if (this != &confirmOrder)
      {
         delete[] m_arrPtr;
         m_arrPtr = nullptr;

         m_count = confirmOrder.m_count;
         confirmOrder.m_count = 0;

         m_arrPtr = confirmOrder.m_arrPtr;
         confirmOrder.m_arrPtr = nullptr;
      }

      return *this;
   }

   ConfirmOrder::~ConfirmOrder()
   {
      delete[] m_arrPtr;
   }

   std::ostream& operator<<(std::ostream& ostr, const ConfirmOrder& confirmOrder)
   {
      ostr << "--------------------------" << endl;
      ostr << "Confirmations to Send" << endl;
      ostr << "--------------------------" << endl;

      if (confirmOrder.m_count > 0)
      {
         for (int i = 0; i < confirmOrder.m_count; i++)
         {
            ostr << *confirmOrder.m_arrPtr[i];
         }
      }
      else
      {
         ostr << "There are no confirmations to send!" << endl;
      }

      ostr << "--------------------------" << endl;

      return ostr;
   }
}