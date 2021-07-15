#include "BulgarianCoin.h"

BulgarianCoin::BulgarianCoin()
{
	Coin::setNationality("BG");
}

void BulgarianCoin::valueCompare()
{
	std::cout << "CONVERT TO:\n1 DE\n2 US\nENTER: ";
	int choice;
	std::cin >> choice;
	if (choice == 1)
	{
		std::cout << this->getValue() << " BulgarianCoin = " << 6 * this->getValue() << " GermanCoin\n";
	}
	else
	{
		std::cout << this->getValue() << " BulgarianCoin = " << 3 * this->getValue() << " AmericanCoin\n";
	}
}

void BulgarianCoin::flip()
{
	int random = rand() % 10; //  0 1 2 3 4 5 6 7 8 9
	if (random <= 2)
	{
		this->setFace(Face::HEADS);
	}
	else
	{
		this->setFace(Face::TAILS);
	}
}