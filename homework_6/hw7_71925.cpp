#include <iostream>
#include "Mob.h"
#include "Hero.h"
#include "Enemies.h"
#include "String.h"

int main()
{
	String s;
	s.setString("hi");

	Enemy e, e1, e2, e3, e4;
	e.print();
	std::cout << std::endl;
	e.setEnemyType(Type::average);

	e1.setIsAlive(0);
	e2.setIsAlive(0);

	Vector<Enemy> vec;
	vec.push_back(e1);
	vec.push_back(e2);
	vec.push_back(e3);
	vec.push_back(e4);

	Enemies en;
	en.setEnemies(vec);

	Hero h;
	h.setHealth(10);
	h.setArmor(22);
	h.print();
	h.setTypeAttack(TypeAttack::splash);
	
	Hero* ptrToHero = &h;
	Enemies* ptrToEnemies = &en;
	Enemy* ptrToEnemy = &e;
	//e.attack(ptrToHero);
	std::cout << std::endl<<"-----------------\n";
	h.attack(ptrToEnemies);
	ptrToHero->print();
}
