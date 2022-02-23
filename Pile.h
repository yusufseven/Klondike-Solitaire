#pragma once
#include "Card.h"

class Pile
{
public:
	
	int cardAmount{};
	
	Card cardArray[19];

	Card popCard();
	void pushCard(Card card);
	bool openTopCard();
	Card peekCardWithIndex(int index);
		
};

