#include "BGpurse.h"

//BGpurse::BGpurse()
//{
//	this->sum = 0;
//}

void BGpurse::setSum(double newSum)
{
	this->sum = newSum;
}
double BGpurse::getSum()const
{
	return this->sum;
}

void BGpurse::printPurse()
{
	std::cout << "MONEY AVAILABLE: " << this->sum << std::endl;
	this->coinToThrow.print();
}

void BGpurse::removeFromPurse(double costOfProduct)
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

void BGpurse::addToPurse(double costOfProduct)
{
	this->sum += costOfProduct;
}

BulgarianCoin BGpurse::getCoinToThrow()const
{
	return this->coinToThrow;
}

void BGpurse::flipCoin()
{
	this->coinToThrow.flip();
}