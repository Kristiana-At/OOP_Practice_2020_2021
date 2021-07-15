#include "Mob.h"
#include "Hero.h"
#include "Enemy.h"
Mob::Mob()
{
	this->name.setString("default");
	this->health = 10;
	this->dmg = 10;
	this->isAlive = true;
}
Mob::Mob(String newName, double newHealth, double newDmg, bool newIsAlive)
{
	setName(newName);
	setHealth(newHealth);
	setDmg(newDmg);
	setIsAlive(newIsAlive);
}

void Mob::die()
{
	setIsAlive(0);
}

void Mob::setName(String newName)
{
	this->name = newName;
}
String Mob::getName()const
{
	return this->name;
}
void Mob::setHealth(double newHealth)
{
	this->health = newHealth;
}
double Mob::getHealth()const
{
	return this->health;
}
void Mob::setDmg(double newDmg)
{
	this->dmg = newDmg;
}
double Mob::getDmg()const
{
	return this->dmg;
}
void Mob::setIsAlive(bool newIsAlive)
{
	this->isAlive = newIsAlive;
}
bool Mob::getIsAlive()const
{
	return this->isAlive;
}
