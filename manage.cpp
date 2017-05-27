#include<iostream>
#include<string.h>
#include<string>
#include<list>
#include<iomanip>
#include<fstream>
#include"manage.h"
#include"Goods.h"

using namespace std;

list<Goods>::iterator manage::match(char name[]) {
	list<Goods>::iterator iter;
	for (iter = goodsInfo.begin(); iter != goodsInfo.end(); iter++)
		if (strcmp(iter->getName(), name) == 0)
			return iter;
    return iter = goodsInfo.end();
}

void manage::add_goods(char name[], int count) {
	list<Goods>::iterator iter = match(name);
	if (iter != goodsInfo.end()) {
		if ((iter->getCount() + count) > 999999999) {
			cout << "\nFailed! Overflow the max stock range of 999999999\n";
			return;
		}
		iter->deposite(count);
	}
	else
		goodsInfo.push_back(Goods(name, count));
	cout << "\nAdd successfully!\nStock " << count << ", remain " << match(name)->getCount() << ".\n";
}

void manage::delete_goods(char name[], int count) {
	list<Goods>::iterator iter = match(name);
	if (iter == goodsInfo.end()) {
		cout << "\nNo such stock\n";
		return;
	}
    if (iter->getCount() < count) {		//������Խ�籨��
        cout << "\nExceed stock balance\n";
        return;
    }
	cout << "\nDelete successfully!\n";
	if (iter->getCount() == count) {	//�������ж��Ƿ�ɾ����Ʒ
		goodsInfo.erase(iter);
		cout << "Out of stock\n";
		return;
	}
	iter->withdraw(count);
	cout << "Remain " << iter->getCount() << "\n";

}

void manage::show_goods() {
    if (goodsInfo.empty()) {	//�ж��Ƿ�ղ�
        cout << "\nEmpty warehouse!\n\n";
        return;
    }
	cout << endl << setw(20) << "Name" << " " << setw(10) << "Count" << endl;
    for (list<Goods>::iterator iter = goodsInfo.begin(); iter != goodsInfo.end(); iter++)
        cout  << setw(20)  << iter->getName() << " " << setw(10) << iter->getCount() << endl;
}

void manage::find_goods(char name[]) {	//�����������ַ���Ϊ�׵�ƥ����׸����
	list<Goods>::iterator iter = match(name);
	if (iter == goodsInfo.end()) {
		cout << "\nNo such stock\n";
		return;
	}
	cout << "\nRemain " << iter->getCount() << "\n";
}

void manage::empty() {
	goodsInfo.clear();
}

void manage::read(string Name) {
	ifstream file;
	file.open(Name.c_str(), ios::in);
	if (file.is_open()) {
		while (file.peek() != EOF) {	//���зֱ��ȡname, count
			char name[100];
			char Count[10];
			file.getline(name, 100);
			file.getline(Count, 10);
			int count = atoi(Count);
			goodsInfo.push_back(Goods(name, count));
		}
		file.close();
	}
}

void manage::save_and_exit(string Name) {
	if (goodsInfo.empty()) {	//�ֿ��ʱɾ���ļ���ɾ����һ�εĲֿ��¼
		remove(Name.c_str());
		exit(0);
	}
	ofstream file(Name.c_str(), ios::trunc);
	if (file.is_open()) {  //name, count��ռһ�У�ʵ��name�ɴ��ո�
		for (list<Goods>::iterator iter = goodsInfo.begin(); iter != goodsInfo.end(); iter++)
			file << iter->getName() << endl << iter->getCount() << endl;
		file.close();
	}
	else {
		cout << "Fail to save the data!";
		system("pause");
	}
	exit(0);
}
