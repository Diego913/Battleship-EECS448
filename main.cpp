#include <iostream>
#include <vector>
#include <string>
#include "Player.h"
#include "Board.h"

int main(int argc, char* argv[])
{
  if(argc<2)
  {
    std::cout<<"Invalid parameters!\n";
  }
  else
  {
    int shipNum=0;
    std::string name1="";
    std::string name2="";

    std::cout<<"Welcome to Battleship!\n";
    std::cout<<"Enter the amount of ships you will play with: ";
    std::cin>>shipNum;
    std::cout<<"Enter the name of Player 1: ";
    std::cin>>name1;
    std::cout<<"Enter the name of Player 2: ";
    std::cin>>name2;

    Board b1;
    b1.printBoard();

  }


}
