#include "Executive.h"

void Executive::displayP1()
{
  board.
}
void Executive::P1Place(int numofShips)
{
    std::cout<<"Player 1, What row would you like to place the front of the ship?";
    std::cin>>row;
    while(isCorrect==0)
    {
      if(row>10 || row<1)
      {
        std::cout<<"Invalid Input, Please try again: ";
        std::cin>>row;
      }
      else
      {
        isCorrect==1;
      }
    }
    std::cout<<"Player 1, What column would you like to place the front of the ship"
    std::cin>>column;
    int col=0;
    isCorrect=0;
    //Converting column into an int so we can use it to place ships
    if(column=='A')
    {
      col=1;
    }
    else if(column=='B')
    {
      col=2;
    }
    else if(column=='C')
    {
      col=3;
    }
    else if(column=='D')
    {
      col=4;
    }
    else if(column=='E')
    {
      col=5;
    }
    else if(column=='F')
    {
      col=6;
    }
    else if(column=='E')
    {
      col=7;
    }
    else if(column=='G')
    {
      col=8;
    }
    else if(column=='H')
    {
      col=9;
    }
    else if(column=='I')
    {
      col=10;
    }
    else
    {
      while(isCorrect==0)
      {
        std::cout<<"Invalid Column, please try again: ";
        std::cin>>column
      }
      else
      {
        isCorrect=1;
      }

    b1.placeShips(row,column);
    std::cout<<"Here is the column you selected: " << column<<"\n";
    std::cout<<"Here is the row you selected: " << row<<"\n";
}

void Executive::P2Place(int numofShips)
{

}

void Executive::P1Attack()
{

}

void Executive::P2Attack()
{

}
