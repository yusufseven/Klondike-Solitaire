#include "Foundation.h"

Card Foundation::popCard(int index)
{
	Card card;
	if(index == 0)
	{
		card = cardArrayHearts[cardAmountHearts - 1];
		cardAmountHearts -= 1;
		return card;	
	}
	
	else if(index == 1)
	{
		card = cardArrayDiamonds[cardAmountDiamonds - 1];
		cardAmountDiamonds -= 1;
		return card;
	}

	else if(index == 2)
	{
		card = cardArraySpades[cardAmountSpades - 1];
		cardAmountSpades -= 1;
		return card;
	}

	else if(index == 3)
	{
		card = cardArrayClubs[cardAmountClubs - 1];
		cardAmountClubs -= 1;
		return card;
	}
	else
	{
		return card;
	}
}

bool Foundation::pushCard(Card card, int index)
{
	if (index == 0)
	{
		if(cardAmountHearts == 0)
		{
			if(card.cardNum != 1)
			{
				return false;
			}			
		}
		else if(card.cardNum != cardArrayHearts[cardAmountHearts - 1].cardNum + 1)
		{
			return false;
		}

		cardArrayHearts[cardAmountHearts] = card;
		cardAmountHearts += 1;
	}
	
	else if (index == 1)
	{
		if (cardAmountDiamonds == 0)
		{
			if (card.cardNum != 1)
			{
				return false;
			}
		}
		else if (card.cardNum != cardArrayDiamonds[cardAmountDiamonds - 1].cardNum + 1)
		{
			return false;
		}
		
		cardArrayDiamonds[cardAmountDiamonds] = card;
		cardAmountDiamonds += 1;
	}

	else if(index == 2)
	{
		if (cardAmountSpades == 0)
		{
			if (card.cardNum != 1)
			{
				return false;
			}
		}
		else if (card.cardNum != cardArraySpades[cardAmountSpades - 1].cardNum + 1)
		{
			return false;
		}
		
		cardArraySpades[cardAmountSpades] = card;
		cardAmountSpades += 1;
	}
	
	else if(index == 3)
	{
		if (cardAmountClubs == 0)
		{
			if (card.cardNum != 1)
			{
				return false;
			}
		}
		else if (card.cardNum != cardArrayClubs[cardAmountClubs - 1].cardNum + 1)
		{
			return false;
		}
		cardArrayClubs[cardAmountClubs] = card;
		cardAmountClubs += 1;
	}

	return true;
}