// Demo01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

char f1(char c)
{
    return c == 'z' ? 'a' : c + 1;
}

char f2(char& c)
{
    c = f1(c);
    return c;
}

class student
{
public:
    int marks;
    void disp()
    {
        std::cout << "its base class";
    }
};

class topper :public student
{
public:
    void disp()
    {
        std::cout << "Its derived class";
    }
};



int main()
{
    student s; topper t;
    s.disp();
    t.disp();

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
