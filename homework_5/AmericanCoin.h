#pragma once
#include "Coin.h"
#include "GermanCoin.h"
#include "BulgarianCoin.h"

class AmericanCoin: public Coin
{
public:
	AmericanCoin();
	void valueCompare();
	void flip();
};

