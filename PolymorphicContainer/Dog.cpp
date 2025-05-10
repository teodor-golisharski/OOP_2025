#include "Dog.h"

Dog::Dog() : Animal(AnimalType::Dog)
{
}

void Dog::roar() const
{
	std::cout << "Woof woof" << std::endl;
}

Animal* Dog::clone() const
{
	Animal* newObj = new (std::nothrow) Dog(*this); //copy constr of Dog
	return newObj;
}