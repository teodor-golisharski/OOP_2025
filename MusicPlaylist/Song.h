#pragma once
class Song
{
	char* title;
	char* author;
	int duration;

	void copyFrom(const Song& other);
	void free();

public:
	Song();
	Song(const Song& other);
	Song& operator=(const Song& other);

	~Song();
};

