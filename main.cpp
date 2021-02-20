#include <iostream>
#include <vector>
#include <string>
#include "Executive.h"
#include "Player.h"
#include "Board.h"

int main()
{

    int shipNum=0;   
    std::cout<<"Welcome to Battleship!\n\n";

    do
    {
      std::cout << "Enter the amount of ships you will play with: Enter (1-6) value \n";
      std::cin >> shipNum;  
      
    } while (shipNum <= 0 || shipNum >=7);
    
    Executive e1(shipNum);
    e1.P1Place();
    e1.P2Place();

    while(true)
    {
      e1.P1Attack();
      if(e1.P1Won())
      {
        std::cout << "PLAYER 1 HAS WON" << std::endl;
        break;
      }

      e1.P2Attack();
      if(e1.P2Won())
      {
        std::cout << "PLAYER 2 HAS WON" << std::endl;
        break;
      }
    }
}
