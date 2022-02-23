#pragma once
#include "Card.h"

class Foundation
{
public:
	int cardAmountHearts{};
	int cardAmountDiamonds{};
	int cardAmountSpades{};
	int cardAmountClubs{};
	
	Card cardArrayHearts[13];
	Card cardArrayDiamonds[13];
	Card cardArraySpades[13];
	Card cardArrayClubs[13];

	Card popCard(int index);				// index 0 = H, index 1 = D, ..... 
	bool pushCard(Card card, int index);	// index 0 = H, index 1 = D, ..... 
};

