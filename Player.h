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



};
#endif
