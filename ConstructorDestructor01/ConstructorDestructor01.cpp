#include <iostream>
//#include <iomanip>

using namespace std;

struct A
{
    A()
    {
        std::cout << "Constructor(default) of A" << std::endl;
    }

    ~A()
    {
        std::cout << "Destructor of A" << std::endl;
    }
};

struct B
{
    B()
    {
        std::cout << "Constructor(default) of B" << std::endl;
    }

    ~B()
    {
        std::cout << "Destructor of B" << std::endl;
    }
};

struct C
{
    C()
    {
        std::cout << "Constructor(default) of C" << std::endl;
    }

    ~C()
    {
        std::cout << "Destructor of C" << std::endl;
    }
};

struct X
{

    X()
    { //calls Constructor(default) of A, Constructor(default) of B, Constructor(default) of C" (x3)
        std::cout << "Constructor of X" << std::endl;
    }

    A first;
    B second;
    C obejectsArray[3];

    
    ~X()
    {
        std::cout << "Destructor of X" << std::endl;
    } //calls Destructor of C" (x3) , Destructor of B, Destructor of A

};

int main()
{
    X  obj; //Constructor of X
} // Destructor of X