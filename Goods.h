#pragma once

class Goods {
private:
	char name[100]; //��¼������
	int count;  //��¼��������
public:
	Goods(const char* Name, const int Count);
	const char* getName() const;
	const int getCount() const;
	void withdraw(int amount);
	void deposite(int amount);
};
