#include "Song.h"
#include <cstring>

#pragma warning (disable : 4996)


void Song::copyFrom(const Song& other)
{
	title = new char[strlen(other.title) + 1];
	strcpy(title, other.title);

	author = new char[strlen(other.author) + 1];
	strcpy(author, other.author);

	duration = other.duration;
}

void Song::free()
{
	delete[] author;
	author = nullptr;
	
	delete[] title;
	title = nullptr;

	duration = 0;
}

Song::Song()
{
	author = nullptr;
	title = nullptr;
}

Song::Song(const Song& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
}

Song& Song::operator=(const Song& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Song::~Song()
{
	free();
}
