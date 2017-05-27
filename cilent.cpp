#include<iostream>
#include<string>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include"cilent.h"
#include"manage.h"
#include"user.h"

using namespace std;

manage user;
control con;

int inputNum() {
	char number[20] = { 0 };
	int Number = 0;
	while (!Number) {
		std::cout << "Only 0 < integer < 1000000000 available\n";
		std::cin >> number;
		if (strlen(number) > 9)
			continue;
		int flag = 0;
		for (int j = 0; j < strlen(number); j++)
			if (number[j] < '0' || number[j] > '9') {
				flag = 1;
				break;
			}
		if(flag)
			continue;
		Number = atoi(number);
	}
	return Number;
}

char* inputName() {
	char* Name=new char[100]();
	int j = 0;
	while (Name[0] == 0 || Name[0] == ' ') {
		if (j++)
			cout << "Error blank. Please retype:\n";
		cin.getline(Name, 100);
	}
	return Name;
}

void printMark() {
	cout << "V2.0 (C)2017 Zhang Jiqi,SYSU. All rights reserved.\n\n";
	string Mark = "Warehouse Management System";
	string spaces(Mark.size() + 2, ' ');
	string decor(Mark.size() + 4, '*');
	cout << decor << "\n*" << spaces << "*\n* " << Mark << " *\n*" << spaces << "*\n" << decor << "\n\n";
}

void printMenu() {
	cout << "1. Add Goods\n\n2. Delete Goods\n\n3. Show Goods\n\n4. Find Goods\n\n5. Empty Warehouse\n\n6. Exit\n\n\n";
	cout << "Input number to choose:";
}

void AddGoods() {
	system("cls");
	printMark();
	std::cout << "*** Add Goods ***\n\nPlease enter the name:\n";
	char*name = inputName();
	std::cout << "Please enter the number:\n";
	int number = inputNum();
	user.add_goods(name, number);
	delete[]name;
}

void DeleteGoods() {
	system("cls");
	printMark();
	cout << "*** Delete Goods ***\n\nPlease enter the name:\n";
	char*name = inputName();
	cout << "Please enter the number:\n";
	int number = inputNum();
	user.delete_goods(name, number);
	delete[]name;
}

void ShowGoods() {
	system("cls");
	printMark();
	std::cout << "*** Show Goods ***\n\n";
	user.show_goods();
}

void FindGoods() {
	system("cls");
	printMark();
	std::cout << "*** Find Goods ***\n\nPlease enter the name:\n";
	char*name = inputName();
	user.find_goods(name);
	delete[]name;
}

void Empty() {
	system("cls");
	printMark();
	user.empty();
	cout << "Successfully empty warehouse\n";
}

void Read() {
	user.read(con.current);
}

void SaveAndExit() {
	user.save_and_exit(con.current);
}

void userInterface() {
	con.read();
	int flag = 0;
	while (1) {
		system("cls");
		cout << "\n1. Login\n\n2. Register\n\n3. Change Password\n\n4. Exit\n\n\n";
		cout << "Input number to choose:";
		string ch;
		cin >> ch;
		cin.ignore();
		if (ch == "1") {
			system("cls");
			if (con.check())
				break;
			else
				cout << "\nUnknown user name or bad password.\n";
		}
		else if (ch == "2") {
			system("cls");
			if (con.increase())
				cout << "\nSuccessfully register.\n";
			else
				cout << "\nUsername already exists\n";
		}
		else if (ch == "3") {
			system("cls");
			if (con.changepassword())
				cout << "\nSuccessfully change password.\n";
			else
				cout << "\nUnknown user name or bad current password.\n";
		}
		else if (ch == "4") {
			flag = 1;
			break;
		}
		else cout << "\nError command!\n";
		cout << "Press any key to return.";
		_getch();
	}
	con.save();
	if (flag)
		exit(0);
}