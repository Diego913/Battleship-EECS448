#include <iostream>
#include <vector>
#include <string>
#include "Executive.h"
#include "Player.h"
#include "Board.h"

int main()
{

    int shipNum=0;
    //bool winCondit=0    std::cout<<"Welcome to Battleship!\n\n";

    do
    {
      std::cout << "Enter the amount of ships you will play with: Enter (1-6) value \n";
      std::cin >> shipNum;  
      
    } while (shipNum <= 0 || shipNum >=7);
    

    //b1.printBoard();

    Executive e1(shipNum);
    e1.P1Place();
    //e1.P2Place(shipNum);

      // while(winCondit==0)
      // {
      //   e1.P1Attack();
      //   if(e1.hasWon()==0)
      //   {
      //     e1.P2Attack();
      //     if(e1.hasWon()==1)
      //     {
      //       winCondit==1;
      //     }
      //   }
      //   else
      //   {
      //     winCondit==1;
      //
      //   }
      //
      // }
std::cout<<"You won!\n";
}
