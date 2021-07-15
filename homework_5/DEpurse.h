#pragma once
#include "GermanCoin.h"
class DEpurse 
{
private:
	double sum = 0;
	GermanCoin coinToThrow;
public:
	void setSum(double newSum);
	double getSum()const;
	
	void printPurse();
	void removeFromPurse(double costOfProduct);
	void addToPurse(double costOfProduct);
	GermanCoin getCoinToThrow()const;
	void flipCoin();
};

