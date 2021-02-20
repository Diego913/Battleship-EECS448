#include<iostream>
#include<string>
#include"Player.h"
#include"Board.h"
#include <vector>

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

class Executive
{
private:
  int row1, row2, col1, col2;
  Player player1();
  Board P1Board1;
  Board P2Board2;
  Board P1AttackBoard;
  Board P2AttackBoard;
  
  bool player1Won = false;
  bool player2Won = false;
  int m_shipNum;
 // int convertCol(char col);
public:
  Executive(int num);
  void P1Place();
  void P2Place();
  void P1Attack();
  void P2Attack();
  bool P1Won();
  bool P2Won();
  /**
  * Takes in user input, it must a number or else user must enter
  * new input.
  *
  * @param int - Beggining of valid input range
  * @param int - End valid input range
  * @return int - Returns valid user input
  **/
  int inputNumber(int begin, int end);
  int inputAlphabet(char begin, char end);
};
#endif
