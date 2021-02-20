Ex1: main.o Board.o Executive.o
	g++ -std=c++11 -g -Wall main.o Board.o Executive.o -o Ex1

main.o: main.cpp Board.h Executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

Board.o: Board.h Board.cpp
	g++ -std=c++11 -g -Wall -c Board.cpp
clean:
	rm *.o Ex1
