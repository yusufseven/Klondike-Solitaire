#pragma once
#include <string>
#include <iostream>
using namespace std;

class Card
{
public:
	int cardNum;
	char cardSuit;
	char color; // r for red, b for black
	bool isCardOpen = false;

	
	Card() = default;
	Card(int num, char suit, bool open);

	string getCardString();
	bool doesConsecutiveFit(Card cardAbove); // check the card above
	int getFoundationIndex();
	string cardToString();
};


