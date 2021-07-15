#pragma once
#include <iostream>
#include "String.h"
//#include "FireCard.h"
#include "CardType.h"
#include <fstream>

class WaterCard
{
private:
	String name;
	int index = 1;
	size_t strength;
	size_t bonusStrength;
public:
	WaterCard();

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
	bool operator==(const WaterCard& other) const;
	friend std::ostream& operator<<(std::ostream& out, const WaterCard& card);

};


