#include <iostream>
#include "Buyer.h"

int main()
{
	srand((unsigned int)time(0));
	Product 
		p1("Chocolate", 5, 40, Face::HEADS),
		p2("Ice Cream", 6, 20, Face::HEADS),
		p3("Milk", 3, 10, Face::TAILS),
		p4("Juice", 2, 20, Face::HEADS),
		p5("Cookies", 7, 60, Face::TAILS),
		p6("Cake", 15, 20, Face::HEADS),
		p7("Coffee", 8, 15, Face::TAILS),
		p8("Salad", 3, 10, Face::HEADS);

	Vector<Product> shop;
	shop.push_back(p1);
	shop.push_back(p2);
	shop.push_back(p3);
	shop.push_back(p4);
	shop.push_back(p5);
	shop.push_back(p6);
	shop.push_back(p7);
	shop.push_back(p8);

	for (size_t i = 0;i < shop.getSize();i++)
	{
		std::cout << i + 1 << ".\n";
		shop[i].print();
		std::cout << std::endl;
	}

	std::cout << "Enter the number of the product you want to buy: ";
	int choice;
	std::cin >> choice;
	choice--;

	Buyer buyer;
	for (size_t i = 0;i < shop.getSize();i++)
	{
		if (i == choice)
		{
			buyer.buy(shop[i]);
			break;
		}
	}
	std::cout << "\n\nYOUR PRODUCTS\n";
	buyer.printBoughtProducts();

}
