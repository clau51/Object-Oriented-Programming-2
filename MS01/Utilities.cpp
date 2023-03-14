#include "Utilities.h"

namespace sdds
{
	char Utilities::m_delim = 0;

	void Utilities::setFieldWidth(size_t newWidth)
	{
		m_widthField = newWidth;
	}

	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{
		std::string tempString{};
		size_t pos = str.find(m_delim, next_pos); //position at the comma
		if (pos == std::string::npos) {
			more = false;
			tempString = str.substr(next_pos);
		}
		else {
			tempString = str.substr(next_pos, pos - next_pos);
			more = true;
			next_pos = pos + 1;
		}
		trim(tempString);

		if (m_widthField < tempString.length()) {
			m_widthField = tempString.length();
		}

		return tempString;
	}

	size_t Utilities::getFieldWidth() const
	{
		return m_widthField;
	}

	char Utilities::getDelimiter()
	{
		return m_delim;
	}

	std::string& Utilities::trim(std::string& s)
	{
		int first = s.find_first_not_of(' ');
		int last = s.find_last_not_of(' ');
		//if (first != -1 && last != -1)
		//{
		s.erase(0, first);
		s.erase(last + 1 - first);
		//}
		//else
		//{
		//   throw "Out of range";
		//}
		return s;

	}

	void Utilities::setDelimiter(char newDelimiter)
	{
		m_delim = newDelimiter;
	}

}
