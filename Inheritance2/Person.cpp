#include "Person.h"
#include <string>
#include <stdexcept>

void Person::copyFrom(const Person& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);

	age = other.age;
}

void Person::free()
{
	delete[] name;
	name = nullptr;
}

void Person::moveFrom(Person&& other)
{
	name = other.name;
	other.name = nullptr;

	age = other.age;
}

Person::Person() : name(nullptr), age(0)
{
}
Person::Person(const char* name, int age)
{
	setName(name);
	setAge(age);
}
Person::Person(const Person& other)
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
Person::Person(Person&& other) noexcept
{
	moveFrom(std::move(other));
}

Person& Person::operator=(Person&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Person::~Person()
{
	free();
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
	if (!name || this->name == name) // can be added aditional check for name correctness 
	{
		throw std::invalid_argument("Invalid name!");
	}

	delete[] name;
	this->name = new char[strlen(name) + 1];

	strcpy(this->name, name);
}
void Person::setAge(int age)
{
	if (age <= 0)
	{
		throw std::invalid_argument("Invalid age!");
	}
	this->age = age;
}
