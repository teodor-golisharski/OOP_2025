#include <iostream>
#include <fstream>

int main()
{
	std::ifstream f("file.bin", std::ios::binary);

	if (!f.is_open())
	{
		return -1;
	}

	int a;

	f.read((char*)&a, sizeof(int));
	std::cout << a << std::endl;

	f.close();
	return 0;
}