#include "Stock.h"
#include <iostream>

using namespace std;

Card Stock::popCard()
{
	Card card;
	
	card = cardArray[cardAmount - 1];
	cardAmount -= 1;
	return card;
}

void Stock::pushCard(Card card)
{
	card.isCardOpen = false;
	cardArray[cardAmount] = card;
	cardAmount += 1;
}

