#include "Pile.h"

Card Pile::popCard()
{
	Card card;

	card = cardArray[cardAmount - 1];
	cardAmount -= 1;
	return card;
}

void Pile::pushCard(Card card)
{
	cardArray[cardAmount] = card;
	cardAmount += 1;
}

bool Pile::openTopCard()
{
	if (cardAmount == 0)
	{
		return false;
	}
	if(cardArray[cardAmount-1].isCardOpen == false)
	{
		cardArray[cardAmount - 1].isCardOpen = true;
		return true;
	}
	else
	{
		return false;
	}
}


Card Pile::peekCardWithIndex(int index)
{
	index = (cardAmount - 1) - index;

	Card card;
	card = cardArray[index];
	return card;
}
