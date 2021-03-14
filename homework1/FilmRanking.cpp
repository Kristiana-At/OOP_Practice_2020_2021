#include "FilmRanking.h"

void FilmRanking::copy(const FilmRanking& other)
{
	setCapacity(other.capacity);
	setSize(other.size);
	this->films = new Film[this->capacity];

	for (int i = 0;i < other.size;i++)
	{
		this->films[i] = other.films[i];
	}
}

void FilmRanking::erase()
{
	delete[] this->films;
}

void FilmRanking::resize()
{
	this->capacity *= 2;
	Film* newFilm = new Film[this->capacity];
	for (int i = 0;i < this->size;i++)
	{
		newFilm[i] = this->films[i];
	}
	erase();
	this->films = newFilm;
}


FilmRanking::FilmRanking()
{
	setCapacity(4);
	setSize(0);
	this->films = new Film[this->capacity];
}

FilmRanking::FilmRanking(const FilmRanking& other)
{
	this->copy(other);
}

FilmRanking& FilmRanking::operator=(const FilmRanking& other)
{
	if (this != &other)
	{
		this->erase();
		this->copy(other);
	}
	return *this;
}

FilmRanking::~FilmRanking()
{
	this->erase();
}

FilmRanking& FilmRanking::addFilm(const Film& addedFilm)
{
	if (this->size == this->capacity) //if equal we must resize the array so as to add new elements
	{
		this->resize();
	}
	this->films[size] = addedFilm;
	this->size++;

	return *this;
}

void FilmRanking::printTopRankedFilms(int numberFilmsForRanking)
{
	Film swapFilm;
	for (int i = 0;i < size - 1;i++) //sort from biggest to smallest
	{
		for (int j = 0;j < size - i - 1;j++)
		{
			if (this->films[j].getNumberOfRewards() < this->films[j + 1].getNumberOfRewards())
			{
				swapFilm = this->films[j];
				this->films[j] = this->films[j + 1];
				this->films[j + 1] = swapFilm;
			}
		}
	}
	for (int i = 0;i < numberFilmsForRanking;i++) //printing
	{
		this->films[i].print();
	}
}

void FilmRanking::setCapacity(int newCapacity)
{
	(newCapacity > 0) ? this->capacity = newCapacity : this->capacity = 0; //validation if the capacity is positive number
}
int FilmRanking::getCapacity()const
{
	return this->capacity;
}

void FilmRanking::setSize(int newSize)
{
	(newSize > 0) ? this->size = newSize : this->size = 0;
}
int FilmRanking::getSize()const
{
	return this->size;
}

Film* FilmRanking::getAllFilms()const
{
	return this->films;
}

