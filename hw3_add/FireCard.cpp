#include "FireCard.h"

FireCard::FireCard()
{
	this->strength = 0;
	this->bonusStrength = 0;
}

void FireCard::setName(String newName)
{
	this->name = newName;
}
String FireCard::getName() const
{
	return this->name;
}

void FireCard::setStrength(size_t newStrenght)
{
	this->strength = newStrenght;
}
size_t FireCard::getStrength()const
{
	return this->strength;
}

void FireCard::setBonusStrength(size_t newBonusStrenght)
{
	this->bonusStrength = newBonusStrenght;
}
size_t FireCard::getBonusStrength()const
{
	return this->bonusStrength;
}

int FireCard::getIndex() const
{
	return this->index;
}

void FireCard::toFile(String fileName)
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

int FireCard::contraPoints() const
{
	return this->strength + this->bonusStrength;
}

void FireCard::print() const
{
	std::cout << "name of card: ";
	this->name.print();
	std::cout << "index: " << this->index << std::endl;
	std::cout << "strength: " << this->strength << std::endl;
	std::cout << "bonus strength: " << this->bonusStrength << std::endl;
}

bool FireCard::operator==(const FireCard& other) const
{
	return this->name == other.name && this->index == other.index && this->strength == other.strength && this->bonusStrength == other.bonusStrength;
}

std::ostream& operator<<(std::ostream& out, const FireCard& card)
{
	out << "name of card: " << card.getName() << "\n";
	out << "index: " << card.index << "\n";
	out << "strength: " << card.strength << "\n";
	out << "bonus strength: " << card.bonusStrength << "\n";
	return out;
}

