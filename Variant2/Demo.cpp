#include "Demo.h"
#include <iostream>

void Person::copyFrom(const Person& other)
{
	setName(other.name);
	setAge(other.age);
}

void Person::free()
{
	delete[] name;
	name = nullptr;

	age = 0;
}

Person::Person() : name(nullptr), age(0) {}

Person::Person(const Person& other) : Person()
{
	copyFrom(other);
}

Person& Person::operator=(const Person& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

const char* Person::getName() const
{
	return name;
}

int Person::getAge() const
{
	return age;
}

void Person::setName(const char* name)
{
	if (name != nullptr)
	{
		delete[] name;

		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
}

void Person::setAge(unsigned age)
{
	this->age = age;
}

Person::~Person()
{
	free();
}
