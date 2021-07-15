#include "WaterCard.h"

WaterCard::WaterCard()
{
	this->strength = 0;
	this->bonusStrength = 0;
}

void WaterCard::setName(String newName)
{
	this->name = newName;
}
String WaterCard::getName() const
{
	return this->name;
}

void WaterCard::setStrength(size_t newStrenght)
{
	this->strength = newStrenght;
}
size_t WaterCard::getStrength()const
{
	return this->strength;
}

void WaterCard::setBonusStrength(size_t newBonusStrenght)
{
	this->bonusStrength = newBonusStrenght;
}
size_t WaterCard::getBonusStrength()const
{
	return this->bonusStrength;
}

int WaterCard::getIndex() const
{
	return this->index;
}

void WaterCard::toFile(String fileName)
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

int WaterCard::contraPoints() const
{
	return this->strength + this->bonusStrength;
}

void WaterCard::print() const
{
	std::cout << "name of card: ";
	this->name.print();
	std::cout << "index: " << this->index << std::endl;
	std::cout << "strength: " << this->strength << std::endl;
	std::cout << "bonus strength: " << this->bonusStrength << std::endl;
}

bool WaterCard::operator==(const WaterCard& other) const
{
	return this->name == other.name && this->index == other.index && this->strength == other.strength && this->bonusStrength == other.bonusStrength;

}

std::ostream& operator<<(std::ostream& out, const WaterCard& card)
{
	out << "name of card: " << card.getName() << "\n";
	out << "index: " << card.index << "\n";
	out << "strength: " << card.strength << "\n";
	out << "bonus strength: " << card.bonusStrength << "\n";
	return out;
}
