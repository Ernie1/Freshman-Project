#pragma once
#include<list>
using namespace std;
class User {
private:
	string username;
	string password;
public:
	User(string Username, string Password);
	const string getusername() const;
	const string getpassword() const;
	void changepassword(string change);
};
class control {
private:
	list<User> users;
	list<User>::iterator match(string Username);
public:
	bool check();
	bool changepassword();
	bool increase();
	void read();
	void save();
	string current;
};