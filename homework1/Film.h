#pragma once
#include<iostream>
class Film
{
private:
	char* name;
	char* directorName;
	int numberOfRewards;

	void copy(const Film& other);
	void erase();

public:
	Film();
	Film(const Film& other);
	Film& operator=(const Film& other);
	~Film();

	void print()const;

	void setName(const char* newName);
	const char* getName()const;

	void setDirectorName(const char* newDirectorName);
	const char* getDirectorName() const;

	void setNumberOfRewards(int newNumberOfRewards);
	int getNumberOfRewards()const;
};


