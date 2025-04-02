#include <iostream>
#include <fstream>

const int BUFF_SIZE = 1024;
const char FILE_NAME[] = "ReadWholeFile.cpp";

int main()
{
	std::ifstream file(FILE_NAME);

	if (!file.is_open())
	{
		std::cout << "Error!" << std::endl;
		return -1;
	}

	char buff[BUFF_SIZE];
	while (true)
	{
		file.getline(buff, BUFF_SIZE);

		if (file.eof())
		{
			break;
		}

		std::cout << buff << std::endl;
	}

	file.close();
}
