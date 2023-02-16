#ifndef SDDS_COLLECTION_H_
#define SDDS_COLLECTION_H_

#include <string>
#include <stdexcept>

namespace sdds
{
   template<typename T>
   class Collection
   {
      std::string m_name{};
      T* m_items{};
      size_t m_size;
      void (*m_fnPtr)(const Collection<T>&, const T&);
   public:
      Collection(const std::string& name)
      {
         m_name = name;
      }

      Collection(const Collection& collection) = delete;
      Collection& operator=(const Collection& collection) = delete;

      ~Collection()
      {
         delete[] m_items;
      }

      const std::string& name() const
      {
         return m_name;
      }

      size_t size() const
      {
         return m_size;
      }

      void setObserver(void (*observer)(const Collection<T>&, const T&))
      {
         m_fnPtr = observer;
      }

      Collection<T>& operator+=(const T& item)
      {
         bool found{};

         for (size_t i = 0; i < m_size && !found; i++)
         {
            if (item.title() == m_items[i].title())
            {
               found = true;
            }
         }

         if (!found)
         {
            T* temp{};
            temp = new T[m_size + 1];

            for (size_t i = 0; i < m_size; i++)
            {
               temp[i] = m_items[i];
            }
            temp[m_size++] = item;

            delete[] m_items;
            m_items = temp;

            if (m_fnPtr)
            {
               m_fnPtr(*this, item);
            }
         }

         return *this;
      }

      T& operator[](size_t index) const
      {
         if (index >= m_size)
         {
            throw std::out_of_range("Bad Index " + std::to_string(index) + ". Collection has " + std::to_string(m_size) + " items.");
         }

         return m_items[index];
      }

      T* operator[](const std::string& title)
      {
         bool found{};
         int index{};
         for (int i = 0; i < m_size && !found; i++)
         {
            if (title == m_items[i].title())
            {
               found = true;
               index = i;
            }
         }

         return found ? &m_items[index] : nullptr;
      }

      friend std::ostream& operator<<(std::ostream& ostr, const Collection<T>& collection)
      {
         for (int i = 0; i < collection.m_size; i++)
         {
            ostr << collection.m_items[i] << std::endl;
         }

         return ostr;
      }

   };

};
#endif