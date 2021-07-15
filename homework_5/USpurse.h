#pragma once
#include "AmericanCoin.h"
class USpurse
{
private:
	double sum = 0;
	AmericanCoin coinToThrow;
public:
	void setSum(double newSum);
	double getSum()const;

	void printPurse();
	void removeFromPurse(double costOfProduct);
	void addToPurse(double costOfProduct);
	AmericanCoin getCoinToThrow()const;
	void flipCoin();
};

