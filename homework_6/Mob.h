#pragma once
#include "String.h"
class Mob
{
private:
	String name;
	double health;
	double dmg;
	bool isAlive;
public:
	Mob();
	Mob(String newName, double newHealth, double newDmg, bool newIsAlive);
	virtual ~Mob() {};

	virtual void attack(Mob* other)const = 0;
	virtual String getType()const = 0;
	virtual void print()const = 0;

	void die();
	void setName(String newName);
	String getName()const;
	void setHealth(double newHealth);
	double getHealth()const;
	void setDmg(double newDmg);
	double getDmg()const;
	void setIsAlive(bool newIsAlive);
	bool getIsAlive()const;
};

