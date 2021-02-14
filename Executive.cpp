#include "Executive.h"
#include"Board.h"


Executive::Executive(int num)
{
  m_shipNum=num;
  P1Board1.setShipNum(num);
}
// void Executive::displayP1()
// {
//
// }
void Executive::P1Place()
{
  char column=' ';
  int row=0;
  bool placing=0;
  bool isCorrect=0;
  int count=m_shipNum;
  while(placing==0)
  {
    isCorrect=0;
    P1Board1.printBoard();
    std::cout<<"Player 1, What row would you like to place the front of the ship: ";
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
        row1=row;
        isCorrect=1;
      }
    }
    std::cout<<"Player 1, What column would you like to place the front of the ship: ";
    std::cin>>column;
    isCorrect=0;
    convertCol(column);
    while(isCorrect==0)
    {
      if(convertCol(column)>=11)
      {
        std::cout<<"Invalid Column, please try again: ";
        std::cin>>column;
        convertCol(column);

      }
      else
      {
        col1=convertCol(column);
        isCorrect=1;
      }

    }
    isCorrect=0;
    std::cout<<"Player 1, What row would you like to place the back of the ship: ";
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
        row2=row;
        isCorrect=1;
      }
    }
    std::cout<<"Player 1, What column would you like to place the back of the ship: ";
    std::cin>>column;
    isCorrect=0;
    convertCol(column);
    while(isCorrect==0)
    {
      if(convertCol(column)>=11)
      {
        std::cout<<"Invalid Column, please try again: ";
        std::cin>>column;
        convertCol(column);

      }
      else
      {
        col2=convertCol(column);
        isCorrect=1;
      }

    }
    std::cout<<row1<<" "<<col1<<" "<<row2<<" "<<col2<<"\n";
    bool check=(P1Board1.checkForShips(row1,col1,row2,col2));
    if(check==0)
    {
      std::cout<<"Invalid placement, please try again\n";
    }
    else
    {

        P1Board1.placeShips(row1,col1,row2,col2);
        std::cout<<"Here is the column you selected: " << col1<<"\n";
        std::cout<<"Here is the row you selected: " << row1<<"\n";
        std::cout<<"Here is the column2 you selected: " << col2<<"\n";
        std::cout<<"Here is the row2 you selected: " << row2<<"\n";
        count--;
        if(count==0)
        {
          placing=1;
          P1Board1.printBoard();
        }

    }

  }
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

int Executive::convertCol(char col)
{
  int convertcol=0;
  //Converting column into an int so we can use it to place ships
  if(col=='A')
  {
    convertcol=1;
  }
  else if(col=='B')
  {
    convertcol=2;
  }
  else if(col=='C')
  {
    convertcol=3;
  }
  else if(col=='D')
  {
    convertcol=4;
  }
  else if(col=='E')
  {
    convertcol=5;
  }
  else if(col=='F')
  {
    convertcol=6;
  }
  else if(col=='E')
  {
    convertcol=7;
  }
  else if(col=='G')
  {
    convertcol=8;
  }
  else if(col=='H')
  {
    convertcol=9;
  }
  else if(col=='I')
  {
    convertcol=10;
  }
  else
  {
    convertcol=50;
  }
  return(convertcol);
}
