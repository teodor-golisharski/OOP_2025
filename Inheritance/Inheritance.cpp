#include <iostream>

class A
{
public:
	A()
	{
		std::cout << "A()" << std::endl;
	}
	~A()
	{
		std::cout << "~A()" << std::endl;
	}
};

class B : public A
{
public:
	B() : A()
	{
		std::cout << "B()" << std::endl;
	}
	~B()
	{
		std::cout << "~B()" << std::endl;
	}
};

class C : protected B
{
public:

	C()
	{
		std::cout << "C()" << std::endl;
	}
	~C()
	{
		std::cout << "~C()" << std::endl;
	}
};

class X
{
public:
	X()
	{
		std::cout << "X()" << std::endl;
	}
	~X()
	{
		std::cout << "~X()" << std::endl;
	}
};


class D : protected X, private C
{
public:

	D()
	{
		std::cout << "D()" << std::endl;
	}
	~D()
	{
		std::cout << "~D()" << std::endl;
	}
};

int main()
{
	C a;
}
