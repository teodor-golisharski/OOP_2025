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
	Person& operator= (const Person& other);

	const char* getName() const;
	int getAge() const;

	void setName(const char* name);
	void setAge(unsigned age);

	~Person();
};

