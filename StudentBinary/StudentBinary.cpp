#include <iostream>
#include <fstream>
#pragma warning (disable: 4996)

struct Student
{
	char* name;
	int gradesCount;
	double averageGrade;
};

namespace studentManager
{
	Student createStudent(const char* name, int gradesCount, double avGrade)
	{
		Student obj;

		size_t nameLen = strlen(name);
		obj.name = new char[nameLen + 1];
		strcpy(obj.name, name);

		obj.gradesCount = gradesCount;
		obj.averageGrade = avGrade;

		return obj;
	}

	void saveStudentToFile(std::ofstream& f, const Student& st)
	{
		size_t nameLen = strlen(st.name);
		f.write((const char*)&nameLen, sizeof(nameLen)); // first we write the size of the name;
		f.write(st.name, nameLen);

		f.write((const char*)&st.gradesCount, sizeof(st.gradesCount));
		f.write((const char*)&st.averageGrade, sizeof(st.averageGrade));
	}

	Student readStudentFromFile(std::ifstream& f)
	{
		Student res;

		size_t nameLen;

		f.read((char*)&nameLen, sizeof(nameLen));

		res.name = new char[nameLen + 1];
		f.read(res.name, nameLen);
		res.name[nameLen] = '\0';

		f.read((char*)&res.gradesCount, sizeof(res.gradesCount));
		f.read((char*)&res.averageGrade, sizeof(res.averageGrade));

		return res;
	}

	void freeStudent(Student& s)
	{
		delete[] s.name;
		s.name = nullptr;

		s.averageGrade = s.gradesCount = 0;

	}

	void print(const Student& st)
	{
		std::cout << st.name << " " << st.gradesCount << " " << st.averageGrade << std::endl;
	}
}

int main()
{
	{
		Student s1 = studentManager::createStudent("Ivan", 2, 4);
		Student s2 = studentManager::createStudent("Petur", 5, 5.5);

		std::ofstream f1("uni.bin", std::ios::binary);

		if (!f1.is_open())
		{
			std::cout << "Error" << std::endl;
			return -1;
		}

		studentManager::saveStudentToFile(f1, s1);
		studentManager::saveStudentToFile(f1, s2);

		studentManager::freeStudent(s1);
		studentManager::freeStudent(s2);

		f1.close();
	}

	{
		std::ifstream f2("uni.bin", std::ios::binary);

		if (!f2.is_open())
		{
			std::cout << "Error" << std::endl;
			return -1;
		}

		Student s1 = studentManager::readStudentFromFile(f2);
		Student s2 = studentManager::readStudentFromFile(f2);

		studentManager::print(s1);
		studentManager::print(s2);

		studentManager::freeStudent(s1);
		studentManager::freeStudent(s2);

		f2.close();
	}
}