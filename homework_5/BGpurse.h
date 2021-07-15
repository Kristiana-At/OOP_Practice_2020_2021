#pragma once
#include "BulgarianCoin.h"
class BGpurse
{
private:
	double sum = 0;
	BulgarianCoin coinToThrow;
public:
	void setSum(double newSum);
	double getSum()const;

	void printPurse();
	void removeFromPurse(double costOfProduct);
	void addToPurse(double costOfProduct);
	BulgarianCoin getCoinToThrow()const;
	void flipCoin();
};

