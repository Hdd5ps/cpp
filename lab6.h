#include <iostream>
#include <iomanip>
using namespace std;

#ifndef LAB6_H
#define LAB6_H
/*
Mason McAlarnis, Kamal Raj Timilsena, Ayden White*/

// function to initialize all 9 spaces to ' '
// pass-by-reference, since we want to change the content in the
// tic-tac-toe board.
void initializeBoard(char ttt[3][3])
{
   const int SIZE = 3;
   for (int i = 0; i < SIZE; i++)
   {
      for (int j = 0; j < SIZE; j++)
      {
         // initialize all cells to ' '
         // this is the same as saying ttt[i][j] = ' ';
         // but this is a little more readable
         char &cell = ttt[i][j];
         cell = ' ';
      }
   }
}

// function to print the board
// pass-by-reference, but can't change anything (nor should we),
// thanks to the const keyword out in front
// prints either x, o, or (empty) depending on what's currently
// occupying the cell.
// print as a 3 x 3 matrix
void printBoard(const char ttt[3][3])
{
   // this one is done for you.
   cout << left;
   for (int i = 0; i < 3; i++)
   {
      for (int j = 0; j < 3; j++)
      {
         cout << setw(10);
         if (ttt[i][j] == ' ')
         {
            cout << "(empty)";
         }
         else
         {
            cout << ttt[i][j];
         }
      }
      cout << endl;
   }
}

// function to check and see if a current space in the board
// is empty/not.  Returns true if the cell is currently ' ',
// otherwise returns false.  The user is attempting to overwrite
// the value currently there.
// the board is declared as constant, since we're only looking
// at the information present.
bool isEmpty(const char ttt[3][3], int row, int col)
{

   if (ttt[row][col] == ' ')
   {
      return true;
   }
   else
   {
      cout << "That cell is already occupied. Please pick another cell." << endl;
      return false;
   }
}
// prompts the user to enter a row and column to place his/her/their pawn
// makes sure if there's a pawn that was previously there that it does not
// get overwritten.  You might find another function listed to be of use
// to you here...
// if the user does enter a currently-occupied cell, the program will
// tell them to pick another cell in the grid

void playerMove(char Play, char tttboard[3][3])
{
   int row, col;
   cout << "Enter the row and column of the cell you want to place your pawn in (O - 2): ";
   cin >> row >> col;
   
   if ((row > 2 || col > 2) || (row < 0 || col < 0)){
      cout << "Out of range. "<<endl;
      cout << "Enter the row and column of the cell you want to place your pawn in (O - 2): ";
      cin >> row >> col;
   }

   // check if the cell is empty
   while (!isEmpty(tttboard, row, col))
   {
      cout << "Enter the row and column of the cell you want to place your pawn in (0 - 2): ";
      cin >> row >> col;
   }

   // place the pawn in the specified cell
   tttboard[row][col] = Play;
   // Play is either 'X' or 'O'
}

// examining a pawn (either Player 1 or Player 2)
// the board isn't modified, so the argument representing
// the board is a constant.  The second argument
// would be the character of the pawn (x for player 1,
// o for player 2
// this function should check and see if any row, column, or
// diagonal has the same pawn
// returns true if some line can be found with the argument pawn in
// all three spots that looks at a potential line.
// if no lines found, return false.
bool isWinner(const char ttt[3][3], char XorO)
{
   if (ttt[0][0] == XorO && ttt[0][1] == XorO && ttt[0][2] == XorO)
   {
      return true;
   }
   else if (ttt[1][0] == XorO && ttt[1][1] == XorO && ttt[1][2] == XorO)
   {
      return true;
   }
   else if (ttt[2][0] == XorO && ttt[2][1] == XorO && ttt[2][2] == XorO)
   {
      return true;
   }
   else if (ttt[0][0] == XorO && ttt[1][0] == XorO && ttt[2][0] == XorO)
   {
      return true;
   }
   else if (ttt[0][1] == XorO && ttt[1][1] == XorO && ttt[2][1] == XorO)
   {
      return true;
   }
   else if (ttt[0][2] == XorO && ttt[1][2] == XorO && ttt[2][2] == XorO)
   {
      return true;
   }
   else if (ttt[0][0] == XorO && ttt[1][1] == XorO && ttt[2][2] == XorO)
   {
      return true;
   }
   else if (ttt[0][2] == XorO && ttt[1][1] == XorO && ttt[2][0] == XorO)
   {
      return true;
   }
   else
   {
      return false;
   }
}
#endif
