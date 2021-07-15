#include "DEpurse.h"

void DEpurse::setSum(double newSum)
{
	this->sum = newSum;
}
double DEpurse::getSum()const
{
	return this->sum;
}

void DEpurse::printPurse()
{
	std::cout << "MONEY AVAILABLE: " << this->sum << std::endl;
	this->coinToThrow.print();
}

void DEpurse::removeFromPurse(double costOfProduct)
{
	if (this->sum >= costOfProduct)
	{
		this->sum -= costOfProduct;
	}
	else
	{
		std::cout << "Not enough money";
	}
}

void DEpurse::addToPurse(double costOfProduct)
{
	this->sum += costOfProduct;
}

GermanCoin DEpurse::getCoinToThrow()const
{
	return this->coinToThrow;
}

void DEpurse::flipCoin()
{
	this->coinToThrow.flip();
}