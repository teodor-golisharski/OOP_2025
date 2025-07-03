#include<iostream>

#pragma once
class Person
{
	char* name;
	int age;

	void copyFrom(const Person& other);
	void free();
public:
	Person();
	Person(const Person& other);
	Person& operator=(const Person& other);

	void setName(const char* name);
	void setAge(int age);

	const char* getName() const;
	int getAge() const;
	virtual ~Person();
};

