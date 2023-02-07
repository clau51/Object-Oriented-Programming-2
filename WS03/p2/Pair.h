#ifndef SDDS_PAIR_H_
#define SDDS_PAIR_H_

#include <string>

namespace sdds
{
	class Pair
	{
		std::string m_key{};
		std::string m_value{};
	public:
		Pair() = default;

		const std::string& getKey();

		const std::string& getValue();

		Pair(const std::string& key, const std::string& value);

		bool operator==(const Pair& p) const;

		friend std::ostream& operator<<(std::ostream& ostr, const Pair& pair);
	};
}

#endif

