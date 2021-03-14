#pragma once
#include<iostream>

class Crypto
{
private:
	char name[30];
	double lastPrice;
	double currentPrice;

public:
	Crypto();
	Crypto(const char* newName, double newLastPrice, double newCurrentPrice);
	double priceDifference();
	void print()const;

	void setName(const char* newName);
	const char* getName()const;
	void setLastPrice(double newLastPrice);
	double getLastPrice()const;
	void setCurrentPrice(double newCurrentPrice);
	double getCurrentPrice()const;
};

