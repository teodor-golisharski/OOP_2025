#pragma once

constexpr size_t MAX_QUOTE_LEN = 30;


class GradStudent
{
	char* name = nullptr;
	int* grades = nullptr;
	size_t gradesCount = 0;
	char quote[MAX_QUOTE_LEN + 1]{};

	void copyFrom(const GradStudent& other);
	void free();

public:
	GradStudent() = default; // DEFAULT
	GradStudent(const GradStudent& other); // COPY CONSTRUCTOR
	GradStudent(const char* name, const int* grade, size_t gradesCount, const char* quote);
	GradStudent& operator=(const GradStudent& other); // OPERATOR =
	~GradStudent(); // DESTRUCTOR

	// SETTER
	void setName(const char* name);
	void setGrades(const int* grades, size_t gradesCount);
	void setQuote(const char* quote);

	// GETTER
	const char* getName() const;
	const int* getGrades() const;
	size_t getGradesCount() const;
	const char* getQuote() const;
};

