#pragma once
#include "Pile.h"
#include "Card.h"
#include <iostream>

using namespace std;

class TableuArea
{
public:
	Pile piles[7];

	Card pileDepoArray[28];	

	void initPiles();
	
	void movePile(int srcPileNum, int srcPileIdx, int destPileIdx);
	// move [ pile <source_pile_num> <source_pile_card_index> ] <destination_pile_num>
	// 
	// remove card
};




