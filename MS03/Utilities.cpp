//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: Mar 18, 2023
//Section: NDD
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#include "Utilities.h"

namespace sdds
{
	char Utilities::m_delim{};

	void Utilities::setFieldWidth(size_t newWidth)
	{
		m_widthField = newWidth;
	}

	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{
		std::string tempString{};

		if (str[next_pos] == m_delim)
		{
			more = false;
			throw "No token found";
		}
		size_t pos = str.find(m_delim, next_pos); //position at the delimiter

		if (pos == std::string::npos) {
			more = false;
			tempString = str.substr(next_pos);
		}
		else {
			tempString = str.substr(next_pos, pos - next_pos);
			more = true;
			next_pos = pos + 1;
		}
		if (m_widthField < tempString.length()) {
			m_widthField = tempString.length();
		}
		trim(tempString);


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

		s.erase(0, first);
		s.erase(last + 1 - first);
		return s;

	}

	void Utilities::setDelimiter(char newDelimiter)
	{
		m_delim = newDelimiter;
	}

}
