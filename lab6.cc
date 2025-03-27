#include "lab6.h"
using namespace std;

/*
This program will implement a game of tic-tac-toe
The functions for the function calls have been put into the .h file,
along with descriptions, to get everything to work.
*/

int main(){
   char player1 = 'X', player2 = 'O';
   //player1 goes first, so X is its pawn
   //player2 goes second, so O is its pawn
   char tttboard[3][3];
   //create the 3 x 3 board necessary
   char continueGame = 't'; //t means currently a tie
   //one of the two flags below necessary to continue the game
   //other possible values are 'x' and 'o'
   initializeBoard(tttboard); //set all cells to spaces
   printBoard(tttboard); //print out the board afterward
   for(int playCount = 0; ((playCount<9)&&(continueGame=='t')); playCount++){
   //when playCount = 1, then all spaces are occupied.
      if(playCount%2 == 0){//player 1's move (comments for player 2 would be the same
         cout<<endl<<"Player 1, your move."<<endl;
         playerMove('X', tttboard);
         //let them make a legal move; checks to see if a player is
         //trying to overwrite what already exists in a particular cell.
      
         if(isWinner(tttboard, 'X')){
         //after making a move, check to see if Player 1 has won yet.
         //if the loop no longer needs to run, change the continue
         //variable so that Player 1 can be declared the winner
            continueGame = 'x';
         }
      
      }
      
      else{//same steps as Player1, but for Player 2 now
         cout<<endl<<"Player2, your move."<<endl;
         playerMove('O', tttboard);
      
         if(isWinner(tttboard, 'O')){
            continueGame = 'o';
         }
      }
      
      
      printBoard(tttboard); //print an updated board
   
   }
   
 //prints game results  
   
   if(continueGame == 'x'){
      cout<<"\nCongratulations, Player 1; you have won."<<endl;
   }
   else if(continueGame == 'o'){
      cout<<"\nCongratulations, Player 2; you have won."<<endl;
   }
   else{
      cout<<"\nTie game; no winner"<<endl;
   }
   
  
   
   return 0;
}