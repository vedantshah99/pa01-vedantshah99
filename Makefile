all: game

game: main.o cards.o utility.o
	g++ main.cpp cards.o utility.o -o game
	
main.o: main.cpp cards.cpp cards.h utility.cpp utility.h
	g++ -c main.cpp utility.cpp cards.cpp

cards.o: cards.cpp cards.h
	g++ -c cards.cpp cards.h

utility.o: utility.cpp utility.h
	g++ -c utility.cpp utility.h

clean:
	rm *.o game
