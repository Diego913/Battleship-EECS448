#include "Executive.h"
#include"Board.h"
#include <cctype>

Executive::Executive(int num)
{
	m_shipNum = num;
	P1Board1.setShipNum(num);
	P1Board1.setShipsVector(num);
	P1Board1.setShipsLeft(num);
	P2Board2.setShipNum(num);
	P2Board2.setShipsVector(num);
	P2Board2.setShipsLeft(num);
}

void Executive::P1Place()
{
	bool placing = true;
	int count = m_shipNum;

	while (placing)
	{
		std::cout << "\n----------------------------------------\n";
		std::cout << "           --Player 1 board--             \n";
		std::cout << "\n----------------------------------------\n";
		P1Board1.printBoard();
		int c;

		while ((c = getchar()) != '\n' && c != EOF);

		if (count == m_shipNum)//count=6
		{
			std::cout << "\n ----------------------------------------\n";
			std::cout << "\nLet's start with the 1x1 ship!\n";
			std::cout << "Player 1, What row would you like to place the 1x1 ship: ";
			row2 = row1 = inputNumber(1, 10);

			std::cout << "Player 1, What column would you like to place the 1x1 ship: ";
			col2 = col1 = inputAlphabet('A', 'J');
		}
		else
		{
			std::cout << "\n----------------------------------------\nThis is a 1x" << (m_shipNum - count) + 1 << " ship.\n";
			std::cout << "Player 1, What row would you like to place the front of the ship: ";
			row1 = inputNumber(1, 10);

			std::cout << "Player 1, What column would you like to place the front of the ship: ";
			col1 = inputAlphabet('A', 'J');

			std::cout << "Player 1, What row would you like to place the back of the ship: ";
			row2 = inputNumber(1, 10);

			std::cout << "Player 1, What column would you like to place the back of the ship: ";
			col2 = inputAlphabet('A', 'J');
		}

		bool check1xN = P1Board1.checkForShips(row1, col1, row2, col2, count);

		if (check1xN == 0)
		{
			std::cout << "Invalid placement, please try again\n";
		}
		else
		{

			P1Board1.placeShips(row1, col1, row2, col2, m_shipNum - count);
			P1Board1.printBoard();
			std::cout << "\n----------------------------------------\n";
			std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
			count--;
		}
		//6 5 4 3 2 1
		if (count == 0)
		{
			placing = false;
		}
	}
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

void Executive::P2Place()
{
	bool placing = true;
	int count = m_shipNum;
	while (placing)
	{
		std::cout << "\n----------------------------------------\n";
		std::cout << "           --Player 2 board--             \n";
		std::cout << "\n----------------------------------------\n";
		P2Board2.printBoard();
		int c;

		while ((c = getchar()) != '\n' && c != EOF);

		if (count == m_shipNum)//count=6
		{
			std::cout << "\n ----------------------------------------\n";
			std::cout << "\nLet's start with the 1x1 ship!\n";
			std::cout << "Player 2, What row would you like to place the 1x1 ship: ";
			row2 = row1 = inputNumber(1, 10);

			std::cout << "Player 2, What column would you like to place the 1x1 ship: ";
			col2 = col1 = inputAlphabet('A', 'J');
		}
		else
		{
			std::cout << "\n----------------------------------------\nThis is a 1x" << (m_shipNum - count) + 1 << " ship.\n";//count=(6-5)+1=2
			std::cout << "Player 2, What row would you like to place the front of the ship: ";
			row1 = inputNumber(1, 10);

			std::cout << "Player 2, What column would you like to place the front of the ship: ";
			col1 = inputAlphabet('A', 'J');

			std::cout << "Player 2, What row would you like to place the back of the ship: ";
			row2 = inputNumber(1, 10);

			std::cout << "Player 2, What column would you like to place the back of the ship: ";
			col2 = inputAlphabet('A', 'J');
		}

		bool check1xN = P2Board2.checkForShips(row1, col1, row2, col2, count);

		if (check1xN == 0)
		{
			std::cout << "\nInvalid placement, please try again\n\n----------------------------------------\n";
		}
		else
		{

			P2Board2.placeShips(row1, col1, row2, col2, m_shipNum - count);
			P2Board2.printBoard();
			std::cout << "\n----------------------------------------\n";
			std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";

			count--;//count=5
		}

		if (count == 0)
		{
			placing = false;
		}
	}
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

void Executive::P1Attack()
{
	int row;
	int col;
	bool attack = true;
	std::cout << "\n----------------------------------------\n";
	std::cout << "           --Player 1 board--             \n";
	std::cout << "\n----------------------------------------\n";
	std::cout << "--This is location of Your ships--\n";
	P1Board1.printBoard();
	std::cout << "\n\n--This is what you attacked--\n";
	P1AttackBoard.printBoard();
	std::cout << "\n----------------------------------------\n";
	while (attack)
	{
		std::cout << "Player 1 turn to attack" << std::endl
			<< "Select Row number: ";

		row = inputNumber(1, 10);

		std::cout << "\nSelect Column letter: ";

		col = inputAlphabet('A', 'J');

		std::cout << "Value: " << P1AttackBoard.checkCoordinates(row - 1, col - 1) << "\n";
		if (P1AttackBoard.checkCoordinates(row - 1, col - 1) == 'M' || P1AttackBoard.checkCoordinates(row - 1, col - 1) == 'H')
		{
			std::cout << "You have already hit or miss here! Choose a new coordinate \n";
			continue;
		}
		else if (P2Board2.checkCoordinates(row - 1, col - 1) == 'S')
		{
			std::cout << "You hit a ship!\n";
			P1AttackBoard.update(row - 1, col - 1, 'H');
			P2Board2.update(row - 1, col - 1, 'H');
			if (P2Board2.isSunk(row - 1, col - 1))
			{
				P2Board2.sinkShip();
				std::cout << "You have sunk a ship!\n";
			}

			if (P2Board2.getShipsLeft() == 0)
			{
				player1Won = true;
			}
		}
		else
		{
			P1AttackBoard.update(row - 1, col - 1, 'M');
			std::cout << "You missed!\n";
		}

		std::cout << "\n----------------------------------------\n";
		std::cout << "--This is location of your own ships--\n";
		P1Board1.printBoard();
		std::cout << "\n\n--This is what you attacked--\n";
		P1AttackBoard.printBoard();
		std::cout << "\n----------------------------------------\n";
		attack = false;
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
	}
}

void Executive::P2Attack()
{
	int row;
	int col;
	bool attack = true;
	std::cout << "\n----------------------------------------\n";
	std::cout << "           --Player 2 board--             \n";
	std::cout << "\n----------------------------------------\n";
	std::cout << "--This is location of your own ships--\n";
	P2Board2.printBoard();
	std::cout << "\n\n--This is what you attacked--\n";
	P2AttackBoard.printBoard();
	std::cout << "\n----------------------------------------\n";
	while (attack)
	{
		std::cout << "Player 2 turn to attack" << std::endl
			<< "Select Row number: ";

		row = inputNumber(1, 10);

		std::cout << "\nSelect Column letter: ";

		col = inputAlphabet('A', 'J');

		std::cout << "Value: " << P2AttackBoard.checkCoordinates(row - 1, col - 1) << "\n";
		if (P2AttackBoard.checkCoordinates(row - 1, col - 1) == 'M' || P2AttackBoard.checkCoordinates(row - 1, col - 1) == 'H')
		{
			std::cout << "You have already hit or miss here! Choose a new coordinate \n";
			continue;
		}
		else if (P1Board1.checkCoordinates(row - 1, col - 1) == 'S')
		{
			std::cout << "You hit a ship!\n";
			P2AttackBoard.update(row - 1, col - 1, 'H');
			P1Board1.update(row - 1, col - 1, 'H');
			if (P1Board1.isSunk(row - 1, col - 1))
			{
				P1Board1.sinkShip();
				std::cout << "You have sunk a ship!\n";

			}

			if (P1Board1.getShipsLeft() == 0)
			{
				player2Won = true;
			}
		}
		else
		{
			P2AttackBoard.update(row - 1, col - 1, 'M');
			std::cout << "You missed!\n";
		}
		std::cout << "\n----------------------------------------\n";
		std::cout << "--This is location of your own ships--\n";
		P2Board2.printBoard();
		std::cout << "\n\n--This is what you attacked--\n";
		P2AttackBoard.printBoard();
		std::cout << "\n----------------------------------------\n";
		attack = false;
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
	}
}

bool Executive::P1Won()
{
	return player1Won;
}

bool Executive::P2Won()
{
	return player2Won;
}

//Fix the row input.
int Executive::inputNumber(int begin, int end)
{
	int v;
	while (true) {
		if (std::cin >> v) {
			if (v >= begin && v <= end) {
				break;
			}
			else {
				std::cout << "The input range is not valid! please retry input!" << std::endl;
			}
		}
		else {
			std::cout << "input not a number! please retry input!" << std::endl;
			std::cin.clear();
			std::cin.ignore();
		}
	}
	return v;
}

//Convert char to number, and also check if the input in a valid range
int Executive::inputAlphabet(char begin, char end) {
	char v;
	while (true) {
		if (std::cin >> v)
		{
			//Convert lower case to uppercase
			if (islower(v))
			{
				v = toupper(v);
			}
			if (v >= begin && v <= end) {
				break;
			}
			else {
				std::cout << "The input range is not valid! please retry input!" << std::endl;
			}
		}
		else {
			std::cout << "input not a alphabet! please retry input!" << std::endl;
			std::cin.clear();
			std::cin.ignore();
		}
	}
	return (v - begin) + 1;
}
