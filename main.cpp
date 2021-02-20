#include <iostream>
#include <vector>
#include <string>
#include "Executive.h"
#include "Board.h"

int main()
{

	int shipNum = 0;
	std::cout << "Welcome to Battleship!\n\n";
	while (true) {
		std::cout << "Enter the amount of ships you will play with: Enter (1-6) value \n";
		if (std::cin >> shipNum)
		{
			if (shipNum < 7 && shipNum > 0)
			{
				break;
			}
			else
			{
				std::cout << "The input range is not valid!\n";
			}
		}
		else
		{
			std::cout << "input not a number!" << std::endl;
			std::cin.clear();
			std::cin.ignore();
		}
	}
	std::cout << "\nThe number of ships are:" << shipNum << "\n\n";

	Executive e1(shipNum);
	e1.P1Place();
	e1.P2Place();

	while (true)
	{
		e1.P1Attack();
		if (e1.P1Won())
		{
			std::cout << "PLAYER 1 HAS WON" << std::endl;
			break;
		}

		e1.P2Attack();
		if (e1.P2Won())
		{
			std::cout << "PLAYER 2 HAS WON" << std::endl;
			break;
		}
	}
}
