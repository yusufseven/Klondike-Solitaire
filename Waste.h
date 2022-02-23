#pragma once
#include "Card.h"

class Waste
{
public:
	int cardAmount{};
	
	Card cardArray[24];

	Card popCard();
	void pushCard(Card card);
	
};

