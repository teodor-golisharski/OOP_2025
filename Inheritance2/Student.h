#pragma once
#include "Person.h"

class Student : public Person
{
	char fn[10];

public:
	Student(const char* name, int age, const char* fn);

	const char* getFn() const;
	void setFn(const char* fn);
};

