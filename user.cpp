#include <iostream>
#include "user.h"
#include <string>

using std::cout;
using std::string;
using std::endl;

User::User(string username,string password){
	this->username = username;
	this->password = password;
}
bool User::addGame(int id){
	games.push_back(id);
	if(games[games.size()-1])
		return true;
}
void User::addFriend(string username){
	userFriends.push_back(username);
	
}
void User::deleteGame(int id){
	
		games.erase(games.begin()+id);
		
}
bool User::deleteFriend(string username){
	for(int i = 0; i < userFriends.size();i++){
		if(userFriends[i] == username){
			userFriends.erase(userFriends.begin()+i);
			return true;
		}
	}
}
void User::changePassword(string password){
	this->password = password;
}
string User::getUsername(){
	return username;
}
bool User::isValidPassword(string username, string password){
	if(username == this->username && password == this->password)
		return true;
}
void User::juegos(){
	for(int i = 0; i < games.size();i++)
		cout << "Posicion: " << i << " " << games[i] << endl;
}
void User::toString(){
	cout << username << "\t" << password << endl;
	cout << "Juegos" << endl;
	for(int i = 0; i < games.size();i++){
		cout << games[i] << endl;
	}
	cout << "Amigos" << endl;
	for(int i = 0; i < userFriends.size();i++){
		cout << userFriends[i] << endl;
	}
}
