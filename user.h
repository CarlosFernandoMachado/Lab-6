#pragma once
#include <string>
#include <vector>
#include <cstring>

using std::string;
using std::vector;

class User{
	string username;
	string password;
	vector<int> games;
	vector<string> userFriends;
public:
	User(string username,string password);
	bool addGame(int id);
	void addFriend(string username);
	void deleteGame(int id);
	bool deleteFriend(string username);
	void changePassword(string password);
	string getUsername();
	bool isValidPassword(string username, string password);
	void juegos();
	void toString();

};
