//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: Feb 5, 2023
//Section: NDD
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <string>
#include <iostream>
#include <iomanip>
#include "Pair.h"

using namespace std;
namespace sdds
{
	const string& Pair::getKey()
	{
		return m_key;
	}

	const string& Pair::getValue()
	{
		return m_value;
	}

	Pair::Pair(const string& key, const string& value) 
		: m_key{ key }, m_value{ value }{};

	bool Pair::operator==(const Pair& p) const
	{
		return m_key == p.m_key;
	}

	ostream& operator<<(ostream& ostr, const Pair& pair)
	{
		return ostr << std::setw(20) << std::right << pair.m_key << ": " << pair.m_value;
	}
}