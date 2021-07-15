#include "GermanCoin.h"

GermanCoin::GermanCoin()
{
	Coin::setNationality("DE");
}

void GermanCoin::valueCompare()const
{
	std::cout << "CONVERT TO:\n1 BG\n2 US\nENTER: ";
	int choice;
	std::cin >> choice;
	if (choice == 1)
	{
		std::cout << this->getValue() << " GermanCoin = " << (1 / 6) * this->getValue() << " BulgarianCoin\n";
	}
	else
	{
		std::cout << this->getValue() << " GermanCoin = " << (2 / 5) * this->getValue() << " AmericanCoin\n";
	}
}

