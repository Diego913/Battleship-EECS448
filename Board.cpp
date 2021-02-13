#include "Board.h"

Board::Board(int num)
{
  m_shipNum=num;
  for(int i=0;i<10;i++)
  {
    for(int k=0;k<10;k++)
    {
      boardP1Ships[i][k]='E';
    }
  }
  for(int i=0;i<10;i++)
  {
    for(int k=0;k<10;k++)
    {
      boardP2Ships[i][k]='E';
    }
  }
  for(int i=0;i<10;i++)
  {
    for(int k=0;k<10;k++)
    {
      boardP1Attack[i][k]='E';
    }
  }
  for(int i=0;i<10;i++)
  {
    for(int k=0;k<10;k++)
    {
      boardP2Attack[i][k]='E';
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

void Board::placeShips(int x1Coor, int y1Coor, int x2Coor, int y2Coor)
{
  int count = m_shipNum;

  while(0 < count)
  {
    if(!checkForShips(x1Coor,y1Coor,x2Coor,y2Coor))
    {
      std::cout << "Enter new coordinates";
    }




      
    if()
    {
      board[row][col] = 'S';
    }
    else 
    {

    }
  }
}

bool Board::checkForShips(int x1, int y1, int x2, int y2)
{

//horizontal
if(x1 == x2)
{
  for(int i = x1; i < x2; i++)
  {
    if(board[i][y1] == "S")
    {
      return false;
    }
  }
} else if(y1 == y2)
{
  for(int i = y1; i < y2; i++)
  {
    if(board[x1][i] == "S")
    {
      return false;
    }
  }
}
else
{
  return false;
}

return true;


}

void Board::attackShips()
{

}

bool Board::isSunk()
{

}

void Board::printBoard()
{
  std::cout<<"     A B C D E F G H I J \n";
  for(int i=0;i<10;i++)
  {
    if(i==0)
    {
      std::cout<<" ";
      std::cout<<" 1| ";
    }
    else if(i==1)
    {
      std::cout<<" ";
      std::cout<<" 2| ";
    }
    else if(i==2)
    {
      std::cout<<" ";
      std::cout<<" 3| ";
    }
    else if(i==3)
    {
      std::cout<<" ";
      std::cout<<" 4| ";
    }
    else if(i==4)
    {
      std::cout<<" ";
      std::cout<<" 5| ";
    }
    else if(i==5)
    {
      std::cout<<" ";
      std::cout<<" 6| ";
    }
    else if(i==6)
    {
      std::cout<<" ";
      std::cout<<" 7| ";
    }
    else if(i==7)
    {
      std::cout<<" ";
      std::cout<<" 8| ";
    }
    else if(i==8)
    {
      std::cout<<" ";
      std::cout<<" 9| ";
    }
    else if(i==9)
    {
      std::cout<<" 10| ";
    }
    for(int k=0;k<10;k++)
    {
      std::cout<<board[i][k];
      std::cout<<" ";
    }
    std::cout<<"\n";
  }
}
