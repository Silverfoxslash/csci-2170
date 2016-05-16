#include "TTT.h"
#include <iostream>
// This function initializes all the elements of the game board to blank characters ' '
TTT::TTT()
{   int x, z;
    for (x=0;x<SIZE;x++)
    {   for(z=0;z<SIZE;z++)
        {gameBoard[x][z]=' ';}
    }
}


// This function displays the game board as a 3 by 3 board
void TTT::Display()const
{
    int x;
    for (x=0; x<SIZE;x++)
    {
        std::cout <<gameBoard[x][0] << " | "<<gameBoard[x][1] << " | "<< gameBoard[x][2]<<std::endl;
        if(x!=2)
            std::cout << "__________" <<std::endl;
    }
   
}
bool TTT::BoardFull()const
{
    int x, z;
    for (x=0;x<SIZE;x++)//checks each index for " "
    {   for(z=0;z<SIZE;z++)
        {if(gameBoard[x][z]==' ')
            return false;
        }
    }
    return true;
}
bool TTT::Assign(int x, int y, char player)
{
    if(gameBoard[x][y]==' ')
    {    gameBoard[x][y]=player;
        return true;
    }
    else 
        return false;
    
}
char TTT::CheckWon()const
{
    char won = 'n';
    int i;
    // write multiway if statement to check whether a win condition is met
    // Case 1: the 3 elements on the i-th row of the array are the same, assign the array element value to variable "won" 
    // Case 2: the 3 elements on the j-th column of the array are the same, assign value to variable "won" 
    // Case 3: the 3 elements on the diagonal of the array are the same, assign value to variable "won"
    // Case 4: the 3 elements of the second diagonal of the array are the same, assign value to variable "won"
    for(i=0;i<SIZE;i++)
    {
        if ((gameBoard[i][0]==gameBoard[i][1])&& (gameBoard[i][1]==gameBoard[i][2])&& gameBoard[i][0] != ' ')
        won=gameBoard[i][0];//checks rows
    }
    
    for(i=0;i<SIZE;i++)
    {
        if ((gameBoard[0][i]==gameBoard[1][i])&& (gameBoard[1][i]==gameBoard[2][i])&& gameBoard[0][i] != ' ')
        won=gameBoard[0][i];//checks colum
        }
   
 if((gameBoard[0][0]==gameBoard[1][1])&& (gameBoard[1][1]==gameBoard[2][2])&& gameBoard[0][0] != ' ')
        won=gameBoard[0][0];//check first diagonal
   
 else if((gameBoard[0][2]==gameBoard[1][1])&& (gameBoard[1][1]==gameBoard[2][0])&& gameBoard[2][0] != ' ')
        won=gameBoard[0][2];//checks 2nd diangal
    return won;
}