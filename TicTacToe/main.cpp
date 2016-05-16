/*Due date: March 25,2016*
Author:Jeremy Bicford
course number:2170-03
This progrom takes makes a ADT of a game of tic tac toe and plays it.
 */
#include "TTT.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
   char turn;
   int x, y;
   // Call the function InitializeBoard to Initialize the game board pieces to blanks
   TTT Game;
   // Randomly determine who is to start the game
   srand(time(0));
   int t=rand()%2;
   if (t == 1)
        turn='X';
   else
        turn='O';
   cout << "Game Starts!" << endl;

   // Display the initial game board on screen
   Game.Display();
   // The game is played between two players until one of two cases occurs:
   // (1) the board is completely filled with pieces from the player, and no winner is determined. 
   // (2) one player wins the game
   while (!Game.BoardFull()&& (Game.CheckWon()=='n'))
   {
   	// Prompt the player to enter the position to play the next move
	// The move is validated in the inner loop. 
	// Only if a move is valid, it will be assigned to the gameboard
       do
       {
          do {
          cout << "Player " << turn << " makes the next move."<<endl;
          cout << "Enter the x, y location, 0<=x<3, 0<=y<3:";
          cin >> x >> y;
          if((x>2 || x<0) || (y>2 || y<0))
              cout << "Invalid cordinates entered\n";
          } while ((x>2 || x<0) && (y>2 || y<0));
       }
       while (!Game.Assign( x, y, turn));
       // The Assign function will attempt to assign a move from a player to the gameboard. IF there is already a piece at that location, Assign function will not put the piece at that location and it returns false. Otherwise, it will put the piece at that location and return true. 

	// Show the updated game board
       Game.Display();

	// determines the player for the next move
       if (turn == 'X')
           turn = 'O';
       else
           turn = 'X';
   }

   // Display the result of the game
   if (Game.CheckWon() == 'X')
      cout << "Player X wins!" << endl;
   else if (Game.CheckWon() == 'O')
      cout << "Player O wins!" << endl;
   else
      cout << "This is a Draw game!" << endl;

    return 0;
}