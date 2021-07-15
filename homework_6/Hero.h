#pragma once
#include "TypeAttack.h"
#include "Mob.h"
#include "Enemy.h"
class Hero : public Mob
{
private:
	TypeAttack typeAttack;
	int armor; //bronq
public:
	void setTypeAttack(TypeAttack newTypeAttack);
	TypeAttack getTypeAttack()const;
	void setArmor(int newArmor);
	int getArmor()const;

	void attack(Mob* other)const override;
	void print()const override;
	String getType()const override;
};

