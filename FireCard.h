#pragma once
#include <iostream>
#include "String.h"
//#include "WindCard.h"
#include "CardType.h"
#include <fstream>

class FireCard
{
private:
	String name;
	int index = 2;
	size_t strength;
	size_t bonusStrength;
public:
	FireCard();

	void setName(String newName);
	String getName()const;
	void setStrength(size_t newStrength);
	size_t getStrength() const;
	void setBonusStrength(size_t newBonusStrength);
	size_t getBonusStrength() const;
	int getIndex()const;
	void toFile(String fileName);
	int contraPoints() const;

	void print()const;
	bool operator==(const FireCard& other) const;
	friend std::ostream& operator<<(std::ostream& out, const FireCard& card);
};


