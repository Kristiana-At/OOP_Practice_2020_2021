#include "Crypto.h"

double Crypto::priceDifference()
{
	if (this->lastPrice != 0)
	{
		return -(100 - ((this->currentPrice * 100) / this->lastPrice));
	}
	return 0;
}

void Crypto::print()const
{
	std::cout << "name: " << this->name << std::endl;
	std::cout << "last price: " << this->lastPrice << std::endl;
	std::cout << "current price: " << this->currentPrice << std::endl;
}

Crypto::Crypto()
{
	setName("default name");
	setLastPrice(0);
	setCurrentPrice(0);
}

Crypto::Crypto(const char* newName, double newLastPrice, double newCurrentPrice)
{
	setName(newName);
	setLastPrice(newLastPrice);
	setCurrentPrice(newCurrentPrice);
}

void Crypto::setName(const char* newName)
{
	strcpy_s(this->name, strlen(newName) + 1, newName);
}
const char* Crypto::getName()const
{
	return this->name;
}

void Crypto::setLastPrice(double newLastPrice)
{
	this->lastPrice = newLastPrice;
}
double Crypto::getLastPrice()const
{
	return this->lastPrice;
}

void Crypto::setCurrentPrice(double newCurrentPrice)
{
	this->currentPrice = newCurrentPrice;
}
double Crypto::getCurrentPrice()const
{
	return this->currentPrice;
}
