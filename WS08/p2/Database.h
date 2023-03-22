#ifndef SDDS_DATABASE_H_
#define SDDS_DATABASE_H_
#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <cstring>
namespace sdds
{
	const int MAX_CAPACITY = 20;

	enum class Err_Status
	{
		Err_Success,
		Err_NotFound,
		Err_OutOfMemory,
	};

	template<typename T>
	class Database
	{
		size_t m_entries{};
		std::string m_key[MAX_CAPACITY]{};
		T m_value[MAX_CAPACITY]{};
		std::string m_filename{};
		static std::shared_ptr<Database<T>> instancePtr;
		Database(const std::string& filename)
		{
			std::cout << std::hex;
			std::cout << "[" << this << "] Database(const std::string&)" << std::endl;

			std::ifstream file(filename);
			if (file)
			{
				m_filename = filename;
				std::string tempKey{};
				T tempValue{};

				while (file.peek() != EOF) {
					file >> tempKey;
					trim(tempKey);
					//std::stringstream ss1(tempKey);
					file >> tempValue;
					//trim(tempValue);
					//std::stringstream ss2(tempValue);
					m_key[m_entries] = tempKey;
					replace(m_key[m_entries].begin(), m_key[m_entries].end(), '_', ' ');
					m_value[m_entries] = tempValue;
					//m_key[m_entries] = tempKey;
					//m_value[m_entries] = tempValue;
					encryptDecrypt(m_value[m_entries]);

					m_entries++;
				}
				//while (getline(file, tempString))
				//{

				//   pos = tempString.find_first_of(' ');
				//   tempKey = tempString.substr(0, pos);
				//   trim(tempKey);
				//   tempValue = tempString.substr(pos + 1, tempString.length());
				//   trim(tempValue);

				//   std::stringstream tv(tempValue);
				//   T tval{};
				//   tv >> tval;

				//   replace(tempKey.begin(), tempKey.end(), '_', ' ');

				//   m_key[m_entries] = tempKey;
				//   m_value[m_entries] = tval;
				//   m_entries++;
				//}


			}

		}
		std::string& trim(std::string& s)
		{
			int first = s.find_first_not_of(' ');
			int last = s.find_last_not_of(' ');

			s.erase(0, first);
			s.erase(last + 1 - first);
			return s;
		}

		void encryptDecrypt(T& value)
		{
		};


	public:
		static std::shared_ptr<Database<T>> getInstance(const std::string& filename)
		{
			return instancePtr ? instancePtr : instancePtr = std::shared_ptr<Database<T>>(new Database<T>(filename));
		}
		Err_Status GetValue(const std::string& key, T& value)
		{
			bool ok{};
			for (size_t i = 0; i < m_entries && !ok; i++)
			{
				if (m_key[i] == key)
				{
					//encryptDecrypt(value);
					value = m_value[i];
					ok = true;
				}
			}
			return ok ? Err_Status::Err_Success : Err_Status::Err_NotFound;
		}

		Err_Status SetValue(const std::string& key, const T& value)
		{
			bool added{};
			if (m_entries < MAX_CAPACITY)
			{
				m_key[m_entries] = key;
				m_value[m_entries] = value;
				m_entries++;
				added = true;
			}
			return added ? Err_Status::Err_Success : Err_Status::Err_OutOfMemory;
		}

		~Database()
		{
			for (size_t i = 0; i < m_entries; i++)
			{
				std::cout << m_key[i] << " earned " << m_value[i] << std::endl;
			}

			std::cout << std::hex;
			std::cout << "[" << instancePtr << "] ~Database()" << std::endl; //or this?

			encryptDecrypt(m_value[0]);
			std::ofstream file(m_filename + ".bkp.txt");
			for (size_t i = 0; i < m_entries; i++)
			{
				file << std::setw(25) << std::left << m_key[i] << "-> " << m_value[i] << std::endl;
			}

		}
	};

	template <typename T>
	std::shared_ptr<Database<T>> Database<T>::instancePtr{};

	template<>
	void Database<std::string>::encryptDecrypt(std::string& value) //hello
	{
		const char secret[]{ "secret encryption key" };

		for (size_t i = 0; i < value.length(); i++)
		{
			for (size_t j = 0; j < std::strlen(secret); j++)
			{
 				value[i] = value[i] ^ secret[j];
			}
		}
	}

	template<>
	void Database<long long>::encryptDecrypt(long long& value)
	{
		const char secret[]{ "super secret encryption key" };
		size_t sz = sizeof(value);
		char* individualByte = reinterpret_cast<char*>(&value);

		for (size_t i = 0; i < sz; i++)
		{
			for (size_t j = 0; j < std::strlen(secret); j++) {
				individualByte[i] = individualByte[i] ^ secret[j];
			}
		}

	}


}

#endif

