#include "Teacher.h"
#include <string>
#pragma warning (disable:4096)

static char** copyArrayOfString(const char* const* strings, size_t size)
{
	char** res = new char* [size];

	for (size_t i = 0; i < size; i++)
	{
		res[i] = new char[strlen(strings[i]) + 1];
		strcpy(res[i], strings[i]);
	}

	return res;
}

static void freeArraysOfString(char** strings, unsigned stringsCount)
{
	for (size_t i = 0; i < stringsCount; i++)
		delete[] strings[i];
	delete[] strings;
}

void Teacher::free()
{
	freeArraysOfString(subjects, subjectsCount);
}

void Teacher::copyFrom(const Teacher& other)
{
	this->subjects = copyArrayOfString(other.subjects, other.subjectsCount);
	this->subjectsCount = other.subjectsCount;
}

void Teacher::moveFrom(Teacher&& other)
{
	subjects = other.subjects;
	subjectsCount = other.subjectsCount;
	other.subjects = nullptr;
	other.subjectsCount = 0;
}

Teacher::Teacher() : subjects(nullptr), subjectsCount(0)
{
}

Teacher::Teacher(const char* name, int age, const char* const* subjects, size_t subjectsCount) : Person(name, age)
{
	this->subjects = copyArrayOfString(subjects, subjectsCount);
	this->subjectsCount = subjectsCount;
}

Teacher::Teacher(const Teacher& other) : Person(other)
{
	copyFrom(other);
}

Teacher& Teacher::operator=(const Teacher& other)
{
	if (this != &other)
	{
		Person::operator=(other); // ⛔️ Първо копира базовата част (може да хвърли изключение)
		free();
		copyFrom(other);
	}
	return *this;
}

Teacher::Teacher(Teacher&& other) noexcept
{
	moveFrom(std::move(other));
}

Teacher& Teacher::operator=(Teacher&& other) noexcept
{
	if (this != &other)
	{
		Person::operator=(std::move(other));
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Teacher::~Teacher()
{
	free();
}
