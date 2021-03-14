#include "Film.h"
void Film::copy(const Film& other)
{
	this->name = new char[strlen(other.name) + 1];
	strcpy_s(this->name, strlen(other.name) + 1, other.name);

	this->directorName = new char[strlen(other.directorName) + 1];
	strcpy_s(this->directorName, strlen(other.directorName) + 1, other.directorName);

	this->numberOfRewards = other.numberOfRewards;
}
void Film::erase()
{
	delete[] name;
	delete[] directorName;
}

Film::Film()
{
	this->name = new char[8];
	setName("default");
	this->directorName = new char[8];
	setDirectorName("default");
	setNumberOfRewards(0);
}

Film::Film(const Film& other)
{
	copy(other);
}

Film& Film::operator=(const Film& other)
{
	if (this != &other)
	{
		copy(other);
	}
	return *this;
}

Film::~Film()
{
	erase();
}

void Film::print()const
{
	std::cout << this->name << std::endl;
	std::cout << this->directorName << std::endl;
	std::cout << this->numberOfRewards << std::endl;
}

void Film::setName(const char* newName)
{
	if (newName != nullptr)
	{
		delete[] this->name;
		this->name = new char[strlen(newName) + 1];
		strcpy_s(this->name, strlen(newName) + 1, newName);
	}
}

const char* Film::getName() const
{
	return this->name;
}

void Film::setDirectorName(const char* newDirectorName)
{
	if (newDirectorName != nullptr)
	{
		delete[] this->directorName;
		this->directorName = new char[strlen(newDirectorName) + 1];
		strcpy_s(this->directorName, strlen(newDirectorName) + 1, newDirectorName);
	}
}

const char* Film::getDirectorName() const
{
	return this->directorName;
}


void Film::setNumberOfRewards(int newNumberOfRewards)
{
	this->numberOfRewards = newNumberOfRewards;
}

int Film::getNumberOfRewards() const
{
	return this->numberOfRewards;
}

