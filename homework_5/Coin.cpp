#include "Coin.h"

Coin::Coin()
{
	setFace(Face::HEADS);
	this->nationality = new char[8];
	setNationality("default");
	setValue(0);
}

Coin::Coin(const Coin& other)
{
	setFace(other.face);
	setNationality(other.nationality);
	setValue(other.value);
}
Coin& Coin::operator=(const Coin& other)
{
	if (this != &other)
	{
		setFace(other.face);
		setNationality(other.nationality);
		setValue(other.value);
	}
	return *this;
}
Coin::~Coin()
{
	delete[] this->nationality;
}

void Coin::flip()
{
	int random = rand() % 2;
	if (random == 0)
	{
		this->face = Face::HEADS;
	}
	else
	{
		this->face = Face::TAILS;
	}
}

void Coin::printEnum()const
{
	if (this->face == Face::HEADS)
	{
		std::cout << "HEADS";
	}
	if (this->face == Face::TAILS)
	{
		std::cout << "TAILS";
	}
}

void Coin::print()const
{
	printEnum();
	std::cout << std::endl;
	std::cout << this->nationality << std::endl;
	std::cout << this->value << std::endl;

}

void Coin::setFace(Face newFace)
{
	if (newFace == Face::HEADS)
	{
		this->face = Face::HEADS;
	}
	if (newFace == Face::TAILS)
	{
		this->face = Face::TAILS;
	}
}
Face Coin::getFace()const
{
	return this->face;
}
void Coin::setNationality(const char* newNationality)
{
	if (newNationality != nullptr)
	{
		delete[] this->nationality;
		this->nationality = new char[strlen(newNationality) + 1];
		strcpy_s(this->nationality, strlen(newNationality) + 1, newNationality);
	}
}
const char* Coin::getNationality()const
{
	return this->nationality;
}
void Coin::setValue(double newValue)
{
	this->value = newValue;
}
double Coin::getValue()const
{
	return this->value;
}