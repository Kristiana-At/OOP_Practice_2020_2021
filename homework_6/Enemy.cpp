#include "Enemy.h"
#include "Hero.h"

void Enemy::attack(Mob* other)const
{
	Hero* hero = dynamic_cast<Hero*>(other);
	if (!hero->getIsAlive())
	{
		return;
	}
	if (this->enemyType == Type::small)
	{
		hero->setHealth(hero->getHealth() - this->getDmg());
	}
	else
	{
		if (this->enemyType == Type::average)
		{
			hero->setDmg(hero->getDmg() * 1.5);
		}
		if (this->enemyType == Type::big)
		{
			hero->setDmg(hero->getDmg() * 2);
		}

		if (hero->getArmor() - this->getDmg() >= 0)
		{
			hero->setArmor(hero->getArmor() - this->getDmg());
		}
		else
		{
			if (hero->getHealth() - this->getDmg() >= 0)
			{
				hero->setHealth(hero->getHealth() - this->getDmg());
			}
		}
	}
	if (hero->getHealth() == 0)
	{
		hero->die();
	}
}

void Enemy::print()const 
{
	std::cout << this->getName() << std::endl
		<< this->getHealth() << std::endl << this->getDmg() << std::endl << this->getIsAlive() << std::endl;
	if (this->enemyType == Type::small)
	{
		std::cout << "small\n";
	}
	if (this->enemyType == Type::average)
	{
		std::cout << "average\n";
	}
	if (this->enemyType == Type::big)
	{
		std::cout << "big\n";
	}
}

String Enemy::getType() const 
{
	String enemy;
	enemy.setString("enemy");
	return enemy;
}
Enemy::Enemy() :Mob()
{
	setEnemyType(Type::small);
}

void Enemy::setEnemyType(Type newType)
{
	if (newType == Type::small)
	{
		this->enemyType = Type::small;
	}
	if (newType == Type::average)
	{
		this->enemyType = Type::average;
	}
	if (newType == Type::big)
	{
		this->enemyType = Type::big;
	}
}
Type Enemy::getEnemyType()const
{
	return this->enemyType;
}

String Enemy::getEnemyTypeString()const
{
	String str;
	if (this->enemyType == Type::small)
	{
		str.setString("small");
	}
	if (this->enemyType == Type::average)
	{
		str.setString("average");
	}
	if (this->enemyType == Type::big)
	{
		str.setString("big");
	}
	return str;
}