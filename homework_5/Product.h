#pragma once
#include<iostream>
#include "Face.h"
class Product
{
private:
	char* name;
	double price;
	double percentDiscount;
	Face hasDiscount;

public:
	Product();
	Product(const Product& other);
	Product& operator=(const Product& other);
	~Product();
	Product(const char* newName, double newPrice, double newPercentDIscount, Face newHasDiscount);

	void print();

	void setName(const char* newName);
	const char* getName()const;
	void setPrice(double newPrice);
	double getPrice()const;
	void setPercentDiscount(double newPercentDiscount);
	double getPercentDiscount()const;
	void setHasDiscount(Face newHasDiscount);
	Face getHasDiscount()const;
};

