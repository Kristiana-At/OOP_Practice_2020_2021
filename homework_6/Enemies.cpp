#include "Enemies.h"

void Enemies::attack(Mob* other)const
{
	size_t size = this->enemies.getSize();
	for (size_t i = 0; i < size; i++)
	{
		this->enemies[i].attack(other);
	}
}

String Enemies::getType()const
{
	String enemy;
	enemy.setString("enemies");
	return enemy;
}

void Enemies::print()const
{
	size_t size = this->enemies.getSize();
	for (size_t i = 0; i < size; i++)
	{
		this->enemies[i].print();
	}
}

void Enemies::setEnemies(Vector<Enemy> newEnemies)
{
	this->enemies = newEnemies;
}

Vector<Enemy> Enemies::getEnemies()const
{
	return this->enemies;
}


std::ostream& operator<<(std::ostream& out, const Enemies& str)
{
	size_t size = str.getEnemies().getSize();
	out << '{';
	for (size_t i = 0; i < size; i++)
	{
		out << '[' << str.getEnemies()[i].getName() << ','
			<< str.getEnemies()[i].getHealth() << ','
			<< str.getEnemies()[i].getDmg() << ','
			<< str.getEnemies()[i].getIsAlive() << ','
			<< str.getEnemies()[i].getEnemyTypeString() << ']';
	}

	out << '}';
	return out;
}

//std::istream& operator>>(std::istream& in, Enemies& str)
//{
//
//}