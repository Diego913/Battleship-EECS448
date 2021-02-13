#include "Board.h"

Board::Board()
{

  for(int i=0;i<10;i++)
  {
    for(int k=0;k<10;k++)
    {
      board[i][k]='E';
    }
  }

   turn=1;
   hitMarker=0;
}

void Board::changeTurn()
{
  if(turn==1)
  {
    turn=0;//Player 2 turn begins.
  }
  else
  {
    turn=1;//Player 1 turn begins.
  }
}

void Board::placeShips()
{

}

void Board::attackShips()
{
  
}

bool Board::isSunk()
{

}

void Board::printBoard()
{
  for(int i=0;i<10;i++)
  {
    for(int k=0;k<10;k++)
    {
      std::cout<<board[i][k];
    }
    std::cout<<"\n";
  }
}
