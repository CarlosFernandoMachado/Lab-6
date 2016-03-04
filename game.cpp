#include <iostream>
#include "game.h"
#include<string>

using std::cout;
using std::endl;
using std::string;

Game::Game(int id, string name, int year, string developers, string genre){
	this->id = id;
	this->name = name;
	this->year = year;
	this->developers = developers;
	this->genre = genre;
}
int Game::getId(){
	return id;
}
void Game::toString(){
	cout << name << "\t" << id << "\t" << year << "\t" << developers << "\t" << genre << "\t" << endl;
}

