#pragma once
#include "Song.h"

class Playlist
{
	Song* songs;

	void copyFrom(const Playlist& other);
	void free();

public:
	Playlist();
	Playlist(const Playlist& other);
	Playlist& operator=(const Playlist& other);

	

	~Playlist();
};

