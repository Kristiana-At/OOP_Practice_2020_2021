#include "WindCard.h"

WindCard::WindCard()
{
	this->strength = 0;
	this->bonusStrength = 0;
}

void WindCard::setName(String newName)
{
	this->name = newName;
}
String WindCard::getName() const
{
	return this->name;
}

void WindCard::setStrength(size_t newStrenght)
{
	this->strength = newStrenght;
}
size_t WindCard::getStrength()const
{
	return this->strength;
}

void WindCard::setBonusStrength(size_t newBonusStrenght)
{
	this->bonusStrength = newBonusStrenght;
}
size_t WindCard::getBonusStrength()const
{
	return this->bonusStrength;
}

int WindCard::getIndex() const
{
	return this->index;
}

void WindCard::toFile(String fileName)
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

int WindCard::contraPoints() const
{
	return this->strength + this->bonusStrength;
}

void WindCard::print() const
{
	std::cout << "name of card: ";
	this->name.print();
	std::cout << "index: " << this->index << std::endl;
	std::cout << "strength: " << this->strength << std::endl;
	std::cout << "bonus strength: " << this->bonusStrength << std::endl;
}

bool WindCard::operator==(const WindCard& other) const
{
	return this->name == other.name && this->index == other.index && this->strength == other.strength && this->bonusStrength == other.bonusStrength;
}

std::ostream& operator<<(std::ostream& out, const WindCard& card)
{
	out << "name of card: " << card.getName() << "\n";
	out << "index: " << card.index << "\n";
	out << "strength: " << card.strength << "\n";
	out << "bonus strength: " << card.bonusStrength << "\n";
	return out;
}

