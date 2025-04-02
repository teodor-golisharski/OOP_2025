#include <iostream>

struct A
{
	int i; // 4
	bool b; // 1
};

struct B
{
	double a; // 8
	int b; // 4
	bool c; // 1
	short d; // 2
};

struct C
{
	int i; // 4
	B b; // 16
};

struct D
{
	double a; // 8
	int b; // 4
	char c[]; // 4
};

struct E
{
	char c;
	int i;
	char c1;
};

/*
struct E
{
 int i;
 char c;
 char c1;
}
*/

struct A1
{
	int a;
	char c;
	double d;
};

struct B1
{
	char arr[3];
};

struct C1
{
	A obj[2];
	C* ptr; // 8
	int a;
	short s;
	B b;
};

union Data
{
	int i;
	char c;
	double d;
};

union MyUnion
{
	char a;         // 1 байт
	int b;          // 4 байта (изисква подравняване на 4 байта)
	double c;       // 8 байта (изисква подравняване на 8 байта)
	short d;        // 2 байта (изисква подравняване на 2 байта)
};

int main()
{
	//std::cout << sizeof(A) << std::endl; // 8
	//std::cout << sizeof(B) << std::endl; // 16
	//std::cout << sizeof(C) << std::endl; // 24
	//std::cout << sizeof(D) << std::endl; // 16
	//std::cout << sizeof(E) << std::endl; // 12

	MyUnion mu;

	mu.a = 'a';
	mu.b = 18;
	
	std::cout << "Size of MyUnion: " << sizeof(MyUnion) << std::endl;

	return 0;
}