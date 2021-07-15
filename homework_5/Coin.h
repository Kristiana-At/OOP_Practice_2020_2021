#pragma once
#include "Face.h"
#include<iostream>
#include <random>
#include "time.h"

class Coin
{
private:
	Face face;
	char* nationality;
	double value;

	void printEnum()const;

public:
	Coin();
	Coin(const Coin& other);
	Coin& operator=(const Coin& other);
	~Coin();

	virtual void flip();
	virtual void print() const;

	void setFace(Face newFace);
	Face getFace()const;
	void setNationality(const char* newNationality);
	const char* getNationality()const;
	void setValue(double newValue);
	double getValue()const;
};

