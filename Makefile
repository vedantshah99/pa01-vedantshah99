all=game

game: main.o cards.o utility.o
	g++ main.cpp cards.o utility.o -o game
	
main.o: main.cpp cards.cpp utility.cpp
	g++ -c main.cpp utility.cpp cards.cpp

cards.o: cards.cpp
	g++ -c cards.cpp

utility.o: utility.cpp
	g++ -c utility.cpp

clean:
	rm *.o game
