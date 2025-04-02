#include <iostream>
#include <fstream>

const char FILE_NAME[] = "FileSize.cpp";

size_t getFileSize(std::ifstream& file)
{
	size_t currPos = file.tellg(); // Връща позицията на текущия символ в потока за четене.
	file.seekg(0, std::ios::end); // Премества get-указателя на последната позиция.
	size_t fileSize = file.tellg(); // Връща позицията на текущия символ (последният в потока за четене).
	file.seekg(currPos); // Премества get-указателя на позция idx на потока за четене (възстановяваме състоянието на указателя).

	return fileSize;
}

int main()
{
	std::ifstream file(FILE_NAME);

	if (!file.is_open())
	{
		std::cout << "Error!" << std::endl;
		return -1;
	}

	std::cout << getFileSize(file) << std::endl;

	return 0;
}