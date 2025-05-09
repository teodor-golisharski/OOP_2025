#include "Student.h"
#include <string>
#include <stdexcept>

Student::Student(const char* name, int age, const char* fn) : Person(name, age)
{
	setFn(fn);
}

const char* Student::getFn() const
{
	return fn;
}

void Student::setFn(const char* fn)
{
	if (!fn || std::strlen(fn) >= 10)
		throw std::invalid_argument("Invalid faculty number!");

	strcpy(this->fn, fn);
}
