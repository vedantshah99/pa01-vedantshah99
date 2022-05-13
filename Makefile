all=game

game: main.cpp tests.o cards.o utility.o
	g++ main.cpp tests.o cards.o utility.o -o game
