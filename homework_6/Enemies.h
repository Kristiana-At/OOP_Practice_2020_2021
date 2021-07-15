#pragma once
#include<iostream>
#include<fstream>
#include "Vector.h"
#include "Enemy.h"

class Enemies :public Mob
{
private:
	Vector<Enemy> enemies;
public:
	String getType() const override;

	void print()const override;
	void attack(Mob* other)const override;
	void setEnemies(Vector<Enemy> newEnemies);
	Vector<Enemy> getEnemies()const;
	void toFile();
	friend std::ostream& operator<<(std::ostream& out, const Enemies& str);
	//friend std::istream& operator>>(std::istream& in, Enemies& str);
};

