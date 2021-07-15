#pragma once
#include "Vector.h"
#include "DEpurse.h"
#include "BGpurse.h"
#include "USpurse.h"
#include "Product.h"

class Buyer
{
private:
	BGpurse bgPurse;
	USpurse usPurse;
	DEpurse dePurse;
	Vector<Product> products;

public:
	Buyer();
	Buyer(BGpurse newBGpurse, USpurse newUSpurse, DEpurse newDEpurse);
	void buy(Product& product);
	void printBoughtProducts()const;
};

