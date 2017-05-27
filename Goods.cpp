#include"Goods.h"
#include<cstring>

Goods::Goods(const char* Name, const int Count) {
	strcpy_s(name, Name);
	count = Count;
}
const char* Goods::getName() const {
	return name;
}
const int Goods::getCount() const {
	return count;
}
void Goods::withdraw(int amount) {
	count -= amount;
}
void Goods::deposite(int amount) {
	count += amount;
}