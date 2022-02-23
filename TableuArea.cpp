#include "TableuArea.h"



void TableuArea::initPiles()
{
	piles[0].cardArray[0] = pileDepoArray[27];	
	piles[1].cardArray[0] = pileDepoArray[26];
	piles[2].cardArray[0] = pileDepoArray[25];	
	piles[3].cardArray[0] = pileDepoArray[24];
	piles[4].cardArray[0] = pileDepoArray[23];
	piles[5].cardArray[0] = pileDepoArray[22];
	piles[6].cardArray[0] = pileDepoArray[21];
	
	piles[1].cardArray[1] = pileDepoArray[20];
	piles[2].cardArray[1] = pileDepoArray[19];
	piles[3].cardArray[1] = pileDepoArray[18];
	piles[4].cardArray[1] = pileDepoArray[17];
	piles[5].cardArray[1] = pileDepoArray[16];
	piles[6].cardArray[1] = pileDepoArray[15];
	
	piles[2].cardArray[2] = pileDepoArray[14];
	piles[3].cardArray[2] = pileDepoArray[13];	
	piles[4].cardArray[2] = pileDepoArray[12];
	piles[5].cardArray[2] = pileDepoArray[11];
	piles[6].cardArray[2] = pileDepoArray[10];
	
	piles[3].cardArray[3] = pileDepoArray[9];
	piles[4].cardArray[3] = pileDepoArray[8];
	piles[5].cardArray[3] = pileDepoArray[7];
	piles[6].cardArray[3] = pileDepoArray[6];
	
	piles[4].cardArray[4] = pileDepoArray[5];
	piles[5].cardArray[4] = pileDepoArray[4];
	piles[6].cardArray[4] = pileDepoArray[3];
	
	piles[5].cardArray[5] = pileDepoArray[2];
	piles[6].cardArray[5] = pileDepoArray[1];
	
	piles[6].cardArray[6] = pileDepoArray[0];

	for (int i = 0; i < 7; i++)
	{
		piles[i].cardArray[i].isCardOpen = true;
		piles[i].cardAmount = i + 1;
	}
}

