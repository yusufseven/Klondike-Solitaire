#include "Card.h"



Card::Card(int num, char suit, bool open)
{
	cardNum = num;
	cardSuit = suit;
	isCardOpen = open;

	if (suit == 'H' || suit == 'D')
	{
		color = 'R';
	}
	else
		color = 'B';
}

string Card::getCardString()
{
	string result = "";
	result += cardSuit;
	if (cardNum < 10)
	{
		result += "0";
	}
	result += to_string(cardNum);
	
	return result;
}

bool Card::doesConsecutiveFit(Card cardAbove)
{
	if((cardAbove.cardNum - 1 == cardNum) && (cardAbove.color != color))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Card::getFoundationIndex()
{
    if (cardSuit == 'H')
    {
		return 0;	
    }

    else if (cardSuit == 'D')
    {
		return 1;
    }

    else if (cardSuit == 'S')
    {
		return 2;
    }

    else
    {
		return 3;
    }
}

string Card::cardToString()
{
	string returnString = string(1, this->cardSuit);
	if (this->cardNum < 10)
	{
		return returnString + "0" + to_string(this->cardNum);
	}
	return returnString + to_string(this->cardNum);
}

