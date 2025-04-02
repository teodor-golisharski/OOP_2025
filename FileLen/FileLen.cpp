#include <iostream>
#include <fstream>

const int BUFF_SIZE = 1024;
const char FILE_NAME[] = "FileLen.cpp";

int main()
{
	std::ifstream file(FILE_NAME);

	if (!file.is_open())
	{
		std::cout << "Error!" << std::endl;
		return -1;
	}

	int count = 0;
	char buffer[BUFF_SIZE];

	while (!file.eof())
	{
		file.getline(buffer, BUFF_SIZE);
		count++;
	}

	std::cout << count << std::endl;

	return 0;
}