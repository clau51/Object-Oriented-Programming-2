//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: Mar 12, 2023
//Section: NDD
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.



#ifndef SDDS_PERSON_H
#define SDDS_PERSON_H
#include <iostream>
#include <string>

namespace sdds
{
	class Person
	{
	public:
		virtual std::string status() const = 0;
		virtual std::string name() const = 0;
		virtual std::string age() const = 0;
		virtual std::string id() const = 0;
		virtual void display(std::ostream&) const = 0;
		
		virtual ~Person() = default;
	};
}

#endif