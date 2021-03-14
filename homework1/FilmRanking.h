#pragma once
#include "Film.h"

class FilmRanking
{
private:
	Film* films;
	int size;
	int capacity;

	void copy(const FilmRanking& other);
	void erase();
	void resize();

public:
	FilmRanking();
	FilmRanking(const FilmRanking& other);
	FilmRanking& operator=(const FilmRanking& other);
	~FilmRanking();

	FilmRanking& addFilm(const Film& addedFilm);
	void printTopRankedFilms(int numberFilmsForRanking);

	void setCapacity(int newCapacity);
	int getCapacity()const;

	void setSize(int newSize);
	int getSize()const;

	Film* getAllFilms()const;
};

