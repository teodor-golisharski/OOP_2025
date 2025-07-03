// demolec2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

class Foo
{
    int bar_;
};

class Base
{
public:
    Base()
    {
        std::cout << "Base конструктор\n";
    }
    Base(int x)
    {
        std::cout << "Base конструктор с параметър " << x << "\n";
    }
};

class Derived : public Base
{
public:
    Derived() : Base(42)
    { // извиква се конструкторът с параметър на базовия
        std::cout << "Derived конструктор\n";
    }
};

class Base1
{
public:
    virtual void foo()
    {
        std::cout << "Base::foo\n";
    }
};

class Derived1 : public Base1
{
public:
    void foo()
    {
        std::cout << "Derived::foo\n";
    }
};

int main()
{
    Derived1 d1;
    Base1* b1 = &d1;
    b1->foo();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
