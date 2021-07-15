#pragma once
#include "Coin.h"
#include "AmericanCoin.h"
#include "BulgarianCoin.h"

class GermanCoin: public Coin
{
public:
	GermanCoin();
	void valueCompare()const;
};

