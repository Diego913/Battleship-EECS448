#include<iostream>
#include<string>
#include"Player.h"
#include"Board.h"

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

class Executive
{
private:
  Board b1(int numofShips);
  int num;
public:
  Executive(int )
  void P1Place(int numofShips);
  void P2Place(int numofShips);
  void P1Attack();
  void P2Attack();

};
#endif
