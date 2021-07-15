#include "EarthCard.h"

EarthCard::EarthCard()
{
	this->strength = 0;
	this->bonusStrength = 0;
}

void EarthCard::setName(String newName)
{
	this->name = newName;
}
String EarthCard::getName() const
{
	return this->name;
}

void EarthCard::setStrength(size_t newStrenght)
{
	this->strength = newStrenght;
}
size_t EarthCard::getStrength()const
{
	return this->strength;
}

void EarthCard::setBonusStrength(size_t newBonusStrenght)
{
	this->bonusStrength = newBonusStrenght;
}
size_t EarthCard::getBonusStrength()const
{
	return this->bonusStrength;
}

int EarthCard::getIndex() const
{
	return this->index;
}

void EarthCard::toFile(String fileName)
{
	fileName += ".txt";
	std::ofstream file;
	file.open(fileName.getString(), std::ios::app);
	if (file.is_open())
	{
		file << this->name.getString() << std::endl;
		file << this->index << std::endl;
		file << this->strength << std::endl;
		file << this->bonusStrength << std::endl;
		file.close();
	}
	else
	{
		std::cout << "Error!" << std::endl;
	}
}

int EarthCard::contraPoints() const
{
	return this->strength + this->bonusStrength;
}

void EarthCard::print() const
{
	std::cout << "name of card: ";
	this->name.print();
	std::cout << "index: " << this->index << std::endl;
	std::cout << "strength: " << this->strength << std::endl;
	std::cout << "bonus strength: " << this->bonusStrength << std::endl;
}

bool EarthCard::operator==(const EarthCard& other) const
{
	return this->name == other.name && this->index == other.index && this->strength == other.strength && this->bonusStrength == other.bonusStrength;
}

std::ostream& operator<<(std::ostream& out, const EarthCard& card)
{
	out << "name of card: " << card.getName() << "\n";
	out << "index: " << card.index << "\n";
	out << "strength: " << card.strength << "\n";
	out << "bonus strength: " << card.bonusStrength << "\n";
	return out;
}
