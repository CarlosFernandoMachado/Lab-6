a.out:	main.o user.o game.o
	g++ main.o user.o game.o -o a.out

user.o:	user.h user.cpp
	g++ -c user.cpp 

game.o:	game.h game.cpp
	g++ -c game.cpp

main.o: main.cpp
	g++ -c main.cpp
