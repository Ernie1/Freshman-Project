#pragma once

class Goods {
private:
	char name[100]; //记录货物名
	int count;  //记录货物数量
public:
	Goods(const char* Name, const int Count);
	const char* getName() const;
	const int getCount() const;
	void withdraw(int amount);
	void deposite(int amount);
};
