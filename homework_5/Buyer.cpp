#include "Buyer.h"

Buyer::Buyer()
{
	this->bgPurse.setSum(50);
	this->usPurse.setSum(40);
	this->dePurse.setSum(30);
	this->products = {};
}

Buyer::Buyer(BGpurse newBGpurse, USpurse newUSpurse, DEpurse newDEpurse)
{
	this->bgPurse = newBGpurse;
	this->usPurse = newUSpurse;
	this->dePurse = newDEpurse;
}

void Buyer::buy(Product& product)
{
	int random = rand() % 3;
	switch (random)
	{
	case 0:
	{
		this->bgPurse.flipCoin();
		BulgarianCoin current = this->bgPurse.getCoinToThrow();//???
		if (current.getFace() == product.getHasDiscount())
		{
			product.setPrice(((100 - product.getPercentDiscount()) / 100) * product.getPrice());
		}
		std::cout << "You have " << this->bgPurse.getSum() << " The product costs " << product.getPrice();	
		if (this->bgPurse.getSum() >= product.getPrice())
		{
			this->products.push_back(product);
			this->bgPurse.removeFromPurse(product.getPrice());
			std::cout << " Successfuly bought the product!\nyour money now is " << this->bgPurse.getSum() << std::endl;
		}
		else
		{
			std::cout << "Not enought money!\n";
		}
		break;
	}
	case 1:
	{
		this->usPurse.flipCoin();
		AmericanCoin current = this->usPurse.getCoinToThrow();//???
		if (current.getFace() == product.getHasDiscount())
		{
			product.setPrice(((100 - product.getPercentDiscount()) / 100) * product.getPrice());
		}
		std::cout << "You have " << this->usPurse.getSum() << " The product costs " << product.getPrice();
		if (this->usPurse.getSum() >= product.getPrice())
		{
			this->products.push_back(product);
			this->usPurse.removeFromPurse(product.getPrice());
			std::cout << " Successfuly bought the product!\nyour money now is " << this->usPurse.getSum() << std::endl;
		}
		else
		{
			std::cout << "Not enought money!\n";
		}
		break;
	}
	case 2:
	{
		this->dePurse.flipCoin();
		GermanCoin current = this->dePurse.getCoinToThrow();//???
		if (current.getFace() == product.getHasDiscount())
		{
			product.setPrice(((100 - product.getPercentDiscount()) / 100) * product.getPrice());
		}
		std::cout << "You have " << this->dePurse.getSum() << " The product costs " << product.getPrice();
		if (this->dePurse.getSum() >= product.getPrice())
		{
			this->products.push_back(product);
			this->dePurse.removeFromPurse(product.getPrice());
			std::cout << " Successfuly bought the product!\nyour money now is " << this->dePurse.getSum() << std::endl;
		}
		else
		{
			std::cout << "Not enought money!\n";
		}
		break;
	}
	default:
	{
		std::cout << "Error bying!\n";
		break;
	}
	}
}

void Buyer::printBoughtProducts()const
{
	size_t size = this->products.getSize();
	for (size_t i = 0; i < size; i++)
	{
		this->products[i].print();
		std::cout << std::endl;
	}
}