#pragma once
#include "Type.h"
#include "Mob.h"
class Enemy : public Mob
{
private:
	Type enemyType; //small average big
public:
	Enemy();

	void setEnemyType(Type newType);
	Type getEnemyType()const;
	void attack(Mob* other)const override;
	void print()const override;
	String getType() const override;
	String getEnemyTypeString()const;
};

