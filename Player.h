#include <iostream>
#include <vector>
#include <string>

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
private:
  std::string name;
  int shipCount;
  int shipsLeft;

public:
  Player();
  int getCount();
  void setCount();
  std::string getName();
  void setName();
  int getShipsLeft();
  void setShipsLeft();
/* ---4boards---
1b- player1 where ships are placed
1b- player1 attacks
1b- player2 where ships are placed
1b- player2 attacks

*/


};
#endif
