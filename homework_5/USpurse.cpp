#include "USpurse.h"

void USpurse::setSum(double newSum)
{
	this->sum = newSum;
}
double USpurse::getSum()const
{
	return this->sum;
}

void USpurse::printPurse()
{
	std::cout << "MONEY AVAILABLE: " << this->sum << std::endl;
	this->coinToThrow.print();
}

void USpurse::removeFromPurse(double costOfProduct)
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

void USpurse::addToPurse(double costOfProduct)
{
	this->sum += costOfProduct;
}

AmericanCoin USpurse::getCoinToThrow()const
{
	return this->coinToThrow;
}

void USpurse::flipCoin()
{
	this->coinToThrow.flip();
}
