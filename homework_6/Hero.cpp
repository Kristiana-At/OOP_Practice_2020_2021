#include "Hero.h"
#include "Enemy.h" //include here so as no to have circular include problems
#include "Enemies.h"

void Hero::attack(Mob* other)const
{
	if (other->getType() == "enemy")
	{
		Enemy* enemy = dynamic_cast<Enemy*>(other);
		if (!enemy->getIsAlive())
		{
			enemy->setHealth(enemy->getHealth() - this->getDmg());
		}

		if (enemy->getHealth() == 0)
		{
			enemy->die();
		}
	}
	if (other->getType() == "enemies")
	{
		Enemies* enemies = dynamic_cast<Enemies*>(other);
		size_t size = enemies->getEnemies().getSize();
		if (this->getTypeAttack() == TypeAttack::splash)
		{
			for (size_t i = 0; i < size; i++)
			{
				if ((enemies + i)->getIsAlive())
				{
					(enemies + i)->setHealth((enemies + i)->getHealth() - this->getDmg());
				}

				if ((enemies + i)->getHealth() == 0)
				{
					(enemies + i)->die();
				}
			}
			
		}
		if (this->getTypeAttack() == TypeAttack::normal)
		{
			for (size_t i = 0; i < size; i++)
			{
				if ((enemies + i)->getIsAlive())
				{
					(enemies + i)->setHealth((enemies + i)->getHealth() - this->getDmg());
					if ((enemies + i)->getHealth() == 0)
					{
						(enemies + i)->die();
					}
					break;
				}
			}
		}
	}
}

void Hero::print()const
{
	std::cout << this->getName() << std::endl
		<< this->getHealth() << std::endl << this->getDmg() << std::endl << this->getIsAlive() << std::endl << this->armor << std::endl;
	if (this->typeAttack == TypeAttack::normal)
	{
		std::cout << "normal\n";
	}
	if (this->typeAttack == TypeAttack::splash)
	{
		std::cout << "splash\n";
	}
}

String Hero::getType()const 
{
	String hero;
	hero.setString("hero");
	return hero;
}

void Hero::setTypeAttack(TypeAttack newTypeAttack)
{
	if (newTypeAttack == TypeAttack::normal)
	{
		this->typeAttack = TypeAttack::normal;
	}
	if (newTypeAttack == TypeAttack::splash)
	{
		this->typeAttack = TypeAttack::splash;
	}
}

TypeAttack Hero::getTypeAttack()const
{
	return this->typeAttack;
}
void Hero::setArmor(int newArmor)
{
	this->armor = newArmor;
}
int Hero::getArmor()const
{
	return this->armor;
}