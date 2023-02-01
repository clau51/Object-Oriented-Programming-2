#ifndef SDDS_PAIR_H_
#define SDDS_PAIR_H_

#include <string>
#include<iostream>
#include <iomanip>

namespace sdds
{
	class Pair
	{
		std::string m_key{};
		std::string m_value{};
	public:
		Pair() = default;

		const std::string& getKey()
		{
			return m_key;
		}

		const std::string& getValue()
		{
			return m_value;
		}

		Pair(const std::string& key, const std::string& value) : m_key{ key }, m_value{ value }{};

		bool operator==(Pair& p) const
		{
			const Pair* pair = dynamic_cast<Pair*>(&p);
			return pair ? m_key == pair->m_key : false;
		}

		friend std::ostream& operator<<(std::ostream& ostr, const Pair& pair)
		{
			ostr << std::setw(20) << pair.m_key;
			ostr << ": ";
			ostr << pair.m_value;

			return ostr;
		}
	};
}

#endif

