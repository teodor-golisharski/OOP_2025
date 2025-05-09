#include "MyString.h"
#pragma warning (disable : 4996)

namespace Utils
{
	static unsigned roundToPowerOfTwo(unsigned v)
	{
		unsigned res = 1;
		while (res < v)
		{
			res *= 2;
		}

		return res;

		// think of a way to do this with bitwise operations and suggest solution as PR
	}

	static unsigned getMaxResizeCapacity(unsigned v)
	{
		// we want to atleast resize with 16
		return std::max(roundToPowerOfTwo(v), 16u); // 16u is used, because we want to return unsigned(u)
	}
}


void MyString::copyFrom(const MyString& other)
{
	capacity = other.capacity;
	data = new char[capacity];
	strcpy(data, other.data);
	size = other.size;
}

void MyString::free()
{
	delete[] data;
	data = nullptr;
	size = 0;
	capacity = 0;
}

void MyString::resize(size_t newCapacity)
{
	char* newData = new char[newCapacity + 1];
	strcpy(newData, data);
	delete[] data;
	data = newData;
	capacity = newCapacity;
}

MyString::MyString() : MyString("")
{
}

MyString::MyString(const char* str)
{
	if (!str)
		str = ""; // some check in case of nullptr

	size = strlen(str);
	capacity = Utils::getMaxResizeCapacity(size);
	data = new char[capacity];
	strcpy(data, str);
}

MyString::MyString(const MyString& other)
{
	copyFrom(other);
}

MyString& MyString::operator=(const MyString& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

MyString::~MyString()
{
	free();
}

size_t MyString::getSize() const
{
	return size;
}

size_t MyString::getCapacity() const
{
	return capacity - 1;
}

const char* MyString::c_str() const
{
	return data;
}

char& MyString::operator[](unsigned index)
{
	return data[index];
}

const char& MyString::operator[](unsigned indexs) const
{
	return data[indexs];
}

MyString& MyString::operator+=(const MyString& other)
{
	if (size + other.size + 1 > capacity)
		resize(Utils::getMaxResizeCapacity(size + other.size));

	strncat(data, other.data, other.size);

	size += other.size;

	return *this;
}

MyString MyString::substr(unsigned begin, unsigned howMany)
{
	if (begin + howMany > size)
		return MyString("");

	MyString res;
	res.capacity = Utils::getMaxResizeCapacity(howMany + 1);
	res.data = new char[res.capacity];
	strncat(res.data, data + begin, howMany);
	res.size = howMany;

	return res;
}

MyString operator+(const MyString& lhs, const MyString& rhs)
{
	MyString temp(lhs);
	temp += rhs;

	return temp;
}

std::ostream& operator<<(std::ostream& os, const MyString& str)
{
	return os << str.data;
}

std::istream& operator>>(std::istream& is, MyString& str)
{
	char buff[1024];
	is >> buff;

	size_t buffStringSize = strlen(buff);
	if (buffStringSize >= str.capacity)
		str.resize(Utils::getMaxResizeCapacity(buffStringSize));

	strcpy(str.data, buff);
	str.size = buffStringSize;

	return is;
}

bool operator==(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

bool operator!=(const MyString& lhs, const MyString& rhs)
{
	return !(lhs == rhs);
}

bool operator>(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}

bool operator>=(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}

bool operator<(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

bool operator<=(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}