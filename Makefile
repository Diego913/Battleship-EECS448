Ex1: main.o Player.o Board.o Executive.o
	g++ -std=c++11 -g -Wall main.o Player.o Board.o Executive.o -o Ex1

main.o: main.cpp Player.h Board.h Executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

Player.o: Player.h Player.cpp
	g++ -std=c++11 -g -Wall -c Player.cpp

Board.o: Board.h Board.cpp
	g++ -std=c++11 -g -Wall -c Board.cpp
