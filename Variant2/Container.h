#pragma once
#include "Demo.h"
class Container
{
	Person** data;
	size_t capacity;
	size_t size;

	void copyFrom(const Container& other);
	void moveFrom(Container&& other);
	void free();
	void resize(size_t newSize);

public:
	Container();

	// CopyFrom
	Container(const Container& other);
	Container& operator=(const Container& other);

	// MoveFrom
	Container(Container&& other) noexcept;
	Container& operator=(Container&& other) noexcept;

	// Destructor
	~Container();

	void add(const Person& obj);
};

