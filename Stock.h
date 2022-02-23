#pragma once
#include "Card.h"

class Stock
{
public:
	Card cardArray[24]{};
	int cardAmount{ 24 };

	Card popCard();
	void pushCard(Card card);
};

