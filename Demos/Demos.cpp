#include<iostream>

struct Box
{
	double height = 1.0;
	double width = 1.0;
	double length = 1.0;
	// double height, width, length; is also possible
};

int main()
{
	//Box b; // default values to height and width and length

	//Box b2 = { 3, 4, 3.4 }; // height = 3, width = 3, length = 3.4;

	//Box b3;
	//b3.height = 13;
	//b3.width = 14;
	//b3.length = 20;

	//std::cout << b.height << " " << b.length << " " << b.width << std::endl;
	//std::cout << b2.height << " " << b2.length << " " << b2.width << std::endl;
	//std::cout << b3.height << " " << b3.length << " " << b3.width << std::endl;

	Box* ptr = new Box();

	(*ptr).height = 2;
	ptr->height = 2;

	return 0;
}