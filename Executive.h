#include<iostream>
#include<string>
#include"Player.h"
#include"Board.h"

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

class Executive
{
private:
  int row1, row2, col1, col2;
  Player player1();
  Board P1Board1;
  int m_shipNum;
  int convertCol(char col);
public:
  Executive(int num);
  void P1Place();
  void P2Place(int numofShips);
  void P1Attack();
  void P2Attack();

};
#endif
