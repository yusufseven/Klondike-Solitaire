#include <iostream>
#include <fstream>
#include <string>
#include "Foundation.h"
#include "Stock.h"
#include "TableuArea.h"
#include "Waste.h"
using namespace std;

TableuArea tableuArea;
Stock stock;
Waste waste;
Foundation foundation;

string getBoard()
{
    std::string board = "";
	if(stock.cardAmount == 0)
	{
           board += "@@@ ";
	}
    else
    {
           board += "___ ";
    }
	
    int totalEmpty = 3;
	for (int i = 1; i<4 && waste.cardAmount - 1 >= 0; i++ )
	{
		if (waste.cardArray[waste.cardAmount - i].isCardOpen)
		{
            totalEmpty--;
		}
	}
    
	for(int i=0; i<3 - totalEmpty; i++ )
	{
        board += waste.cardArray[waste.cardAmount - 1 - i].cardToString() + " ";
	}
	
	for(int i=0; i<totalEmpty; i++)
	{
        board += "___ ";
	}
    board += "        ";

    board += foundation.cardAmountHearts == 0 ? "___ " : foundation.cardArrayHearts[foundation.cardAmountHearts - 1].cardToString() + " ";
    board += foundation.cardAmountDiamonds == 0 ? "___ " : foundation.cardArrayDiamonds[foundation.cardAmountDiamonds - 1].cardToString() + " ";
    board += foundation.cardAmountSpades == 0 ? "___ " : foundation.cardArraySpades[foundation.cardAmountSpades - 1].cardToString() + " ";
    board += foundation.cardAmountClubs == 0 ? "___ " : foundation.cardArrayClubs[foundation.cardAmountClubs - 1].cardToString() + " ";
    board += "\n\n";
	

    int maxPileLength = 0;
	for (int i=0; i<7; i++)
	{
        maxPileLength = max(maxPileLength, tableuArea.piles[i].cardAmount);
	}

	for(int i=0; i<maxPileLength; i++)
	{
		for (int k=0; k<7; k++)
		{
			if(tableuArea.piles[k].cardAmount - 1 >= i)
			{
                board += tableuArea.piles[k].cardArray[i].isCardOpen ? tableuArea.piles[k].cardArray[i].cardToString() : "@@@";
                board += "   ";
			}
            else
            {
                board += "      ";
            }
		}
        board += "\n";
	}

	if (maxPileLength == 0)
	{
        board += "                                          \n";
	}
	
	
    return board;
}


//int main(int argc, char* argv[])
int main()
{
	//reading deck
    ifstream fileDeck("deck.txt"); // argv[1]
    ofstream outputFile("output.txt");// argv[3]
    	
    

    int indexCard = 0;
    int depoIndex = 0;
    for (string lineDeck; getline(fileDeck, lineDeck);)
    {
       
    	if (indexCard < 24)
    	{
            Card card = Card(stoi(lineDeck.substr(1)) ,lineDeck[0], false);
            stock.cardArray[indexCard] = card;
            indexCard++;
            //cout << card.getCardString() << endl; // first 24 cards  
    	}     
    	
        else
        {            
            Card card = Card(stoi(lineDeck.substr(1)), lineDeck[0], false);
            tableuArea.pileDepoArray[depoIndex] = card;       
            depoIndex++;
            //cout << card.getCardString() << endl; // last 28 cards
        }
    	
    }

    tableuArea.initPiles();

	

    //reading commands
    ifstream fileCommands("commands.txt"); // argv[3]
    string lineCommands;
    string word;
	
    outputFile << "\n" + getBoard() << "\n";
	
    while (std::getline(fileCommands, lineCommands))
    {
        outputFile << lineCommands << "\n\n";
    	
        if (lineCommands[0] == 'm')
        {       
           if (lineCommands[5] == 't')
           {
	           if (lineCommands[19] == 'p')
	           {
					// move to foundation pile (num)
                   int pileNum = stoi(lineCommands.substr(24));
                   if (tableuArea.piles[pileNum].cardAmount == 0)
                   {
                       outputFile << "Invalid move!\n\n";
                   }
                   else
                   {
						Card tempCard = tableuArea.piles[pileNum].popCard();
                   	
                        if (!foundation.pushCard(tempCard, tempCard.getFoundationIndex()))
                        {
                            outputFile << "Invalid move!\n\n";
                            tableuArea.piles[pileNum].pushCard(tempCard);
                        }
                   	 
                   }	           		
	           }
           	
               else
               {
	               // move to foundation waste
               		if (waste.cardAmount == 0)
               		{
                        outputFile << "Invalid move!\n\n";
               		}
                    else
                    {
                        Card tempCard = waste.popCard();

                        if (!foundation.pushCard(tempCard, tempCard.getFoundationIndex()))
                        {
                            outputFile << "Invalid move!\n\n";
                            waste.pushCard(tempCard);
                        }
                    }

                   
               }
           }
           
           else
           {
	           if (lineCommands[5] == 'p')
	           {
		           //move pile (src num)(src idx)(destination num)
                   int pileNum = stoi(lineCommands.substr(10));
                   int cardIndex = stoi(lineCommands.substr(12));
                   int destinationNum = stoi(lineCommands.substr(14));
                   if (tableuArea.piles[pileNum].cardAmount - 1 < cardIndex)
                   {
                       outputFile << "Invalid move!\n\n";;
                   }
                   else
                   {
	                   Card peekedCard = tableuArea.piles[pileNum].peekCardWithIndex(cardIndex);
	                   if (tableuArea.piles[destinationNum].cardAmount == 0)
	                   {
	                        if (peekedCard.cardNum == 13)
	                        {
	                            for (int i = cardIndex; i >= 0; i--)
	                            {
	                                tableuArea.piles[destinationNum].pushCard(tableuArea.piles[pileNum].peekCardWithIndex(i));
	                            }

	                            for (int i = cardIndex; i >= 0; i--)
	                            {
	                                tableuArea.piles[pileNum].popCard();
	                            }
	                        }
	                        else
	                        {
                                outputFile << "Invalid move!\n\n";
	                        }
	                   }
                       else if(peekedCard.doesConsecutiveFit(tableuArea.piles[destinationNum].peekCardWithIndex(0)))
                       {
	                       for(int i= cardIndex; i >= 0; i--)
	                       {
                               tableuArea.piles[destinationNum].pushCard(tableuArea.piles[pileNum].peekCardWithIndex(i));
	                       }
                       	
                           for (int i = cardIndex; i >= 0; i--)
                           {
                               tableuArea.piles[pileNum].popCard();
                           }                      		
                       }
                       else
                       {
                           outputFile << "Invalid move!\n\n";
                       }
                   }	           	

	           }
               else if (lineCommands[5] == 'w')
               {          
	               //move waste (pile destination num)
                   int destinationNum = stoi(lineCommands.substr(11));
	               if (waste.cardAmount == 0)
	               {
                       outputFile << "Invalid move!\n\n";
	               }
	               else
	               {
	                    Card poppedCard = waste.popCard();

	                    if (tableuArea.piles[destinationNum].cardAmount == 0)
	                    {
							if(poppedCard.cardNum == 13)
							{
                                tableuArea.piles[destinationNum].pushCard(poppedCard);
							}
                            else
                            {
                                waste.pushCard(poppedCard);
                                outputFile << "Invalid move!\n\n";
                            }
	                    }
                        else if(poppedCard.doesConsecutiveFit(tableuArea.piles[destinationNum].peekCardWithIndex(0)))
                        {
                            tableuArea.piles[destinationNum].pushCard(poppedCard);
                        }
                        else
                        {
                            waste.pushCard(poppedCard);
                            outputFile << "Invalid move!\n\n";
                        }
	               		if(waste.cardAmount != 0)
	               		{
                            bool anyOpen = false;
	               			for(int i=0; i < waste.cardAmount; i++)
	               			{
	               				if (waste.cardArray[i].isCardOpen)
	               				{
                                    anyOpen = true;
                                    break;
	               				}
	               			}
	               			if (!anyOpen)
	               			{
                                waste.cardArray[waste.cardAmount - 1].isCardOpen = true;
	               			}
	               		}	               		
	               }	
               }
               else
               {
	               //move foundation (source foundation num16) (destination pile num18)
                   int srcFoundationNum = stoi(lineCommands.substr(16));
                   int destinationNum = stoi(lineCommands.substr(18));
                   if(srcFoundationNum == 0 && foundation.cardAmountHearts == 0)
                   {
                       outputFile << "Invalid move!\n\n";
                   }
                   else if(srcFoundationNum == 1 && foundation.cardAmountDiamonds == 0)
                   {
                       outputFile << "Invalid move!\n\n";
                   }
                   else if(srcFoundationNum == 2 && foundation.cardAmountSpades == 0)
                   {
                       outputFile << "Invalid move!\n\n";
                   }
                   else if (srcFoundationNum == 3 && foundation.cardAmountClubs == 0)
                   {
                       outputFile << "Invalid move!\n\n";
                   }
               	
                   else 
                   {
                       Card poppedCard = foundation.popCard(srcFoundationNum);

                       if (tableuArea.piles[destinationNum].cardAmount == 0)
                       {
                           if (poppedCard.cardNum == 13)
                           {
                               tableuArea.piles[destinationNum].pushCard(poppedCard);
                           }
                           else
                           {
                               foundation.pushCard(poppedCard, srcFoundationNum);
                               outputFile << "Invalid move!\n\n";
                           }
                       }
                       else if (poppedCard.doesConsecutiveFit(tableuArea.piles[destinationNum].peekCardWithIndex(0)))
                       {
                           tableuArea.piles[destinationNum].pushCard(poppedCard);
                       }
                       else
                       {
                           foundation.pushCard(poppedCard, srcFoundationNum);
                           outputFile << "Invalid move!\n\n";
                       }
                   }
               }
           }      
        }

    	
        else if(lineCommands[0] == 'o') // open...
        {
	        if(lineCommands[5] == 'f')
	        {
	        	//open from stock
                if(stock.cardAmount == 0)
                {
                    int j = waste.cardAmount;
                	for (int i=0; i < j; i++) // just in case if popCard changing the cardAmount causes a problem
                	{
                        stock.pushCard(waste.popCard());
                	}             	
                }
                else
                {
                    for(int i=0; i<waste.cardAmount; i++)
                    {
                        waste.cardArray[i].isCardOpen = false;
                    }
                	
                	int transferableCardCount = std::min(3, stock.cardAmount);
                    for(int i=0; i < transferableCardCount; i++)
                    {
                        Card tempCard = stock.popCard();
                        tempCard.isCardOpen = true;      	
                        waste.pushCard(tempCard);
                    }
                }
	        	
	        	
	        }
            else
            {
	            //open (pile num)
                int pileNum = stoi(lineCommands.substr(5));
                bool success = tableuArea.piles[pileNum].openTopCard();
                if (success == false)
                {
                    outputFile << "Invalid move!\n\n";
                }
            }
        }
    	        

        else if (lineCommands == "exit") 
        {
        	//exit
            outputFile << "****************************************\n\n";
            break;
        }

        outputFile << "****************************************\n";
        outputFile << getBoard()<<"\n";
        if (foundation.cardAmountHearts == 13 && foundation.cardAmountDiamonds == 13 && foundation.cardAmountSpades == 13 && foundation.cardAmountClubs == 13)
        {
            outputFile << "You Win!\n\n";
        }
    	
        
    }
    outputFile << "****************************************\n\n";
    outputFile << "Game over!";
   
	
	
}