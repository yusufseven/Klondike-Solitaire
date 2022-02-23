#include "Waste.h"

Card Waste::popCard()
{
	Card card;

	card = cardArray[cardAmount - 1];
	cardAmount -= 1;
	return card;
}

void Waste::pushCard(Card card)
{
	card.isCardOpen = true;
	cardArray[cardAmount] = card;
	cardAmount += 1;
}