#include<iostream>
#include<stdio.h>
#include<string>
#include<conio.h>
#include<Windows.h>
#include"cilent.h"

using namespace std;

int main() {
	printMark();
	cout << "\nLoading...";
	Sleep(1000);
	userInterface();
	cout << "\nSuccessfully login.\n\nLoading...";
	Sleep(1000);
    Read();
    while (1) {     //Menu
        system("cls");
        printMark();
        printMenu();
        string ch;
        cin >> ch;
		cin.ignore();
		if (ch == "1") AddGoods();
        else if (ch == "2") DeleteGoods();
		else if (ch == "3") ShowGoods();
		else if (ch == "4") FindGoods();
		else if (ch == "5") Empty();
		else if (ch == "6") SaveAndExit();
		else cout << "Error command!\n";
		cout << "\nPress any key to return.";
		_getch();
    }
    return 0;
}
