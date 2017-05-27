#include"user.h"
#include<list>
#include<string>
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<fstream>
using namespace std;

string Password() {
	char password[100]="\0";
	int index = 0;
	while (1) {
		char ch;
		ch = _getch();
		if (ch == 8) {
			if (index != 0) {
				std::cout << char(8) << " " << char(8);
				index--;
			}
		}
		else if (ch == '\r') {
			password[index] = '\0';
			cout << endl;
			if(password[0]!=0)
				break;
		}
		else {
			std::cout << "*";
			password[index++] = ch;
		}
	}
	string tem(password);
	return tem;
}
list<User>::iterator control::match(string Username) {
	list<User>::iterator iter;
	for (iter = users.begin(); iter != users.end(); iter++)
		if (iter->getusername() == Username)
			return iter;
	return iter = users.end();
}
bool control::check() {
	cout << "Username:\n";
	string Username;
	cin >> Username;
	cout << "Password:\n";
	string password(Password());
	if (match(Username) == users.end())
		return false;
	if (match(Username)->getpassword() != password)
		return false;
	current = Username;
	return true;
}
bool control::changepassword() {
	cout << "Username:\n";
	string Username;
	cin >> Username;
	cout << "Current Password:\n";
	string password(Password());
	if (match(Username) == users.end())
		return false;
	if (match(Username)->getpassword() != password)
		return false;
	cout << "New Password:\n";
	string newpassword(Password());
	match(Username)->changepassword(newpassword);
	return true;
}
bool control::increase() {
	cout << "New Username:\n";
	string Username;
	cin >> Username;
	if (match(Username) != users.end())
		return false;
	cout << "New Password:\n";
	users.push_back(User(Username, Password()));
	return true;
}
void control::read() {
	ifstream file;
	file.open("user", ios::in);
	if (file.is_open()) {
		while (file.peek() != EOF) {
			string username, password;
			getline(file, username);
			getline(file, password);
			users.push_back(User(username, password));
		}
		file.close();
	}
}
void control::save() {
	ofstream file("user", ios::trunc);
	if (file.is_open()) {
		for (list<User>::iterator iter = users.begin(); iter != users.end(); iter++)
			file << iter->getusername() << endl << iter->getpassword() << endl;
		file.close();
	}
	else {
		cout << "Fail to save accounts!";
		system("pause");
	}
}
User::User(string Username, string Password) {
	username = Username;
	password = Password;
}
const string User::getusername() const {
	return username;
}
const string User::getpassword() const {
	return password;
}
void User::changepassword(string change) {
	password = change;
}
