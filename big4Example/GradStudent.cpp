#include "GradStudent.h"
#include <cstring>

#pragma warning (disable : 4996)


void GradStudent::copyFrom(const GradStudent& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);

	grades = new int[other.gradesCount];
	gradesCount = other.gradesCount;

	for (size_t i = 0; i < other.gradesCount; i++)
	{
		grades[i] = other.grades[i];
	}
	strcpy(quote, other.quote);
}

void GradStudent::free()
{
	delete[] name;
	name = nullptr;
	delete[] grades;
	grades = nullptr;

	gradesCount = 0;
	strcpy(quote, "");
}

GradStudent::GradStudent(const GradStudent& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
}

GradStudent::GradStudent(const char* name, const int* grade, size_t gradesCount, const char* quote)
{
	setName(name);
	setGrades(grade, gradesCount);
	setQuote(quote);
}

GradStudent& GradStudent::operator=(const GradStudent& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

GradStudent::~GradStudent()
{
	free();
}

void GradStudent::setName(const char* name)
{
	if (!name || this->name == name)
	{
		return;
	}

	delete[] this->name;
	this->name = new char[strlen(name) + 1] {};

	strcpy(this->name, name);

}

void GradStudent::setGrades(const int* grades, size_t gradesCount)
{
	if (!grades || this->grades == grades)
	{
		return;
	}

	delete[] grades;

	this->grades = new int[gradesCount];
	this->gradesCount = gradesCount;

	for (size_t i = 0; i < gradesCount; i++)
	{
		this->grades[i] = grades[i];
	}
}

void GradStudent::setQuote(const char* quote)
{
	if (!quote || strlen(quote) > MAX_QUOTE_LEN)
	{
		return;
	}

	strcpy(this->quote, quote);
}

const char* GradStudent::getName() const
{
	return name;
}

const int* GradStudent::getGrades() const
{
	return grades;
}

size_t GradStudent::getGradesCount() const
{
	return gradesCount;
}

const char* GradStudent::getQuote() const
{
	return quote;
}
