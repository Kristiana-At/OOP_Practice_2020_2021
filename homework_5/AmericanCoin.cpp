#include "AmericanCoin.h"

AmericanCoin::AmericanCoin()
{
	Coin::setNationality("US");
}

void AmericanCoin::valueCompare()
{
	std::cout << "CONVERT TO:\n1 BG\n2 DE\nENTER: ";
	int choice;
	std::cin >> choice;
	if (choice == 1)
	{ 
		std::cout << this->getValue() << " AmericanCoin = " << (1 / 3) * this->getValue() << " BulgarianCoin\n";
	}
	else
	{
		std::cout << this->getValue() << " AmericanCoin = " << (2.5) * this->getValue() << " GermanCoin\n";
	}
}

void AmericanCoin::flip()
{
	int random = rand() % 10; 
	if (random <= 8)
	{
		this->setFace(Face::HEADS);
	}
	else
	{
		this->setFace(Face::TAILS);
	}
}