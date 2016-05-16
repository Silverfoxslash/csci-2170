/*Due date: March 15,2016*
Author:Jeremy Bicford
course number:2170-03
This progrom takes makes a deck of cards, shuffles it, then deals cards to four player, and finds the playe with the two of diamonds
 */
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
const int players=4;
const int maxHand=13;
const int maxSize=52;
	//structure definition
struct cardType
{
    string suit;
    int rank;
    int value;
};

void buildDeck(cardType cardDeck[],int maxSize,int& count);
void printHand(int players, cardType playerHands[][maxHand]);
void ShuffleCards(cardType cardDeck[], int count);
void printDeck(int count, cardType cardDeck[]);
void DealCards(cardType playerHands[][maxHand], int players, cardType cardDeck[], int count);
void sortCards(int players, cardType playerHands[][maxHand]);
bool startFirst(int players, cardType playerHands[][maxHand]);
//main function
int main()
{
      // An array of cards named deck, size 52
    cardType cardDeck[maxSize];
    cardType playerHands[players][maxHand];
    
    int count;
    buildDeck(cardDeck,maxSize,count);
    ShuffleCards(cardDeck, count);
    DealCards(playerHands, players, cardDeck, count);
    sortCards(players, playerHands);
    printHand( players, playerHands);
    startFirst(players, playerHands);
    return 0;

}
void buildDeck(cardType cardDeck[],int maxSize,int& count)
{
     int x;
     count=0;
    
    for (x=0; x <maxSize; x++)
    {
        if (x/13==0)//first 13 cards are diamond
        {
            cardDeck[count].suit = "Diamond";         
            cardDeck[count].rank = x+1;
            if (x == 11)
                cardDeck[count].value=-100;
            else
               cardDeck[count].value= 0;
        }
        else if (x/13==1) //second 13 cards are clubs
        {
            cardDeck[count].suit = "Club";         
            cardDeck[count].rank = (x%13)+1;
            cardDeck[count].value= 0;
        }
        else if (x/13==2)//thrid 13 cards are heart
        {
            cardDeck[count].suit = "Heart";         
            cardDeck[count].rank = x%26+1;
            if (x%26<10)
                cardDeck[count].value= 5;
            else
                cardDeck[count].value=10;
        }
         else//last cards are spade
        {
            cardDeck[count].suit = "Spade";         
            cardDeck[count].rank = x%39+1;
            if (x%39 == 11)
                cardDeck[count].value= 100;
            else
                cardDeck[count].value=0;
        }
        count ++;
    }
}



//funcution loops and prints the playrs hand
void printHand(int players, cardType playerHands[][maxHand])
{
    int x,z;
    for (z = 0; z < players ; z++)
    {   //print header
        cout << right;
        cout << "\nPLAYER "<< z+1 << endl;
        
        cout << " SUIT" << setw(13) << "RANK"<< setw(14)<< "POINTS"<< endl;
        for(x = 0; x < maxHand; x++)
        {
            cout<< left;
            cout <<setw(14)<<playerHands[z][x].suit;
            cout << right;
            switch(playerHands[z][x].rank)//if face card print letter 
            {
                case(1):cout << setw(2)<< "A";
                    break;
                case(11):cout << setw(2)<< "J";
                    break;
                case(12):cout << setw(2)<< "Q";
                    break;
                case(13):cout << setw(2)<< "K";
                    break;
                default:cout << setw(2)<< playerHands[z][x].rank;// if not print number
            }
            cout << setw(14)<< playerHands[z][x].value<< endl;
        }
    }
}

//shuffles by swaping two random indexes of deck 100 times
void ShuffleCards(cardType cardDeck[], int count)
{
    srand(time(0));//uses time as a seed number
    int x,rand1,rand2;
    cardType temp;
    for (x=0; x<100; x++)
    {
        rand1=rand()%52;//random number1
        rand2=rand()%52;//random number2
        
        temp=cardDeck[rand1];
        cardDeck[rand1]=cardDeck[rand2];
        cardDeck[rand2]=temp;
    }
}
//deals cards lopping through deck passing cards one at a time
void DealCards(cardType playerHands[][maxHand], int players, cardType cardDeck[], int count)
{
    int x;
    int player1Count=0;
    int player2Count=0;
    int player3Count=0;
    int player4Count=0;
    
    for(x=0; x<count;x++)
    {
            if (x%4==0)
            {
                playerHands[0][player1Count]=cardDeck[x];
                player1Count++;
            }
            if (x%4==1)
            {
                playerHands[1][player2Count]=cardDeck[x];
                player2Count++;
            }
            if (x%4==2)
            {
                playerHands[2][player3Count]=cardDeck[x];
                player3Count++;
            }
            
            if (x%4==3)    
            {
                playerHands[3][player4Count]=cardDeck[x];
                player4Count++;
            }
    }
}
//seclection sort by suit and rank
void sortCards(int players, cardType playerHands[][maxHand])
{
    cardType temp;
    int x, z, a;
    //sort suits first
    for (z=0; z < players ; z ++)
    {
        for(x=0; x < maxHand; x++)
        {
            for(a=x+1; a<maxHand; a++)
            if (playerHands[z][x].suit <= playerHands[z][a].suit)
                {
                    temp=playerHands[z][x];
                    playerHands[z][x]=playerHands[z][a];
                    playerHands[z][a]=temp;                    
                }
        }
    }
    //thn sort ranks
    for (z=0; z < players ; z ++)
    {
        for(x=0; x < maxHand; x++)
        {
            for(a=x+1; a<maxHand; a++)
            if (playerHands[z][x].suit <= playerHands[z][a].suit)
               if ((playerHands[z][x].suit == playerHands[z][a].suit)&&(playerHands[z][x].rank<playerHands[z][a].rank))
                {
                    temp=playerHands[z][x];
                    playerHands[z][x]=playerHands[z][a];
                    playerHands[z][a]=temp;                    
                }
        }
    }
    
}
//loops in nested loop to find 2 of diamonds
bool startFirst(int players, cardType playerHands[][maxHand])
{
    int z,x;
    for (z=0; z < players ; z ++)
    {
        for(x=0; x < maxHand; x++)
        {
            if ((playerHands[z][x].suit=="Diamond")&&(playerHands[z][x].rank==2))
                {
                 cout << "Player "<< z+1 << " is to start the game.\n";
                return true;
                }
        }
    }
    return false;
}