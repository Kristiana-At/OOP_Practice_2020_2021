#pragma once
#include "Coin.h"
#include "AmericanCoin.h"
#include "GermanCoin.h"

class BulgarianCoin : public Coin
{
public:
	BulgarianCoin();
	void valueCompare();
	void flip();
};

