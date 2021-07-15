#include "Product.h"
Product::Product(): Product("default", 0, 0, Face::HEADS)
{
}

Product::Product(const Product& other)
{
	setName(other.name);
	setPrice(other.price);
	setPercentDiscount(other.percentDiscount);
	setHasDiscount(other.hasDiscount);
}
Product& Product::operator=(const Product& other)
{
	if (this != &other)
	{
		setName(other.name);
		setPrice(other.price);
		setPercentDiscount(other.percentDiscount);
		setHasDiscount(other.hasDiscount);
	}
	return *this;
}
Product::~Product()
{
	delete[] this->name;
}

Product::Product(const char* newName, double newPrice, double newPercentDIscount, Face newHasDiscount) :name(nullptr)
{
	setName(newName);
	setPrice(newPrice);
	setPercentDiscount(newPercentDIscount);
	setHasDiscount(newHasDiscount);
}

void Product::print()
{
	std::cout << this->name << std::endl;
	std::cout << price << std::endl;
	std::cout << percentDiscount << std::endl;
	if (this->hasDiscount == Face::HEADS)
	{
		std::cout << "HEADS\n";
	}
	if (this->hasDiscount == Face::TAILS)
	{
		std::cout << "TAILS\n";
	}
}

void Product::setName(const char* newName)
{
	if (newName != nullptr)
	{
		delete[] this->name;
		this->name = new char[strlen(newName) + 1];
		strcpy_s(this->name, strlen(newName) + 1, newName);
	}
}
const char* Product::getName()const
{
	return this->name;
}
void Product::setPrice(double newPrice)
{
	this->price = newPrice;
}
double Product::getPrice()const
{
	return this->price;
}
void Product::setPercentDiscount(double newPercentDiscount)
{
	this->percentDiscount = newPercentDiscount;
}
double Product::getPercentDiscount()const
{
	return this->percentDiscount;
}
void Product::setHasDiscount(Face newHasDiscount)
{
	if (newHasDiscount == Face::HEADS)
	{
		this->hasDiscount = Face::HEADS;
	}
	if (newHasDiscount == Face::TAILS)
	{
		this->hasDiscount = Face::TAILS;
	}
}
Face Product::getHasDiscount()const
{
	return this->hasDiscount;
}