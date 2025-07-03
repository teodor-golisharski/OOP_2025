#include "Person.h"

void Person::free()
{
	delete[] name;
}

void Person::setAge(int age)
{
	this->age = age;
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

const char* Person::getName() const
{
	return this->name;
}

int Person::getAge() const
{
	return this->age;
}

void Person::copyFrom(const Person& other)
{
	setName(other.name);
	setAge(other.age);
}

Person::Person() : age(0), name(nullptr)
{
}

Person::~Person()
{
	free();
}

Person::Person(const Person& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
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