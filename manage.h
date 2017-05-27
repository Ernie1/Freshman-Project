#pragma once
#include<list>
#include"Goods.h"

using namespace std;

class manage {
private:
	list<Goods> goodsInfo;
	list<Goods>::iterator match(char name[]);
public:
	//�Զ�����
	void add_goods(char name[], int count);
	//�Զ�����
	void delete_goods(char name[], int count);
	//��ʾ��ǰ���
	void show_goods();
	//�鿴�ֿ��е�name��Ʒ
	void find_goods(char name[]);

	void empty();
	//�����ļ����ݶ�ȡ
	void read(string Name);
	//�����ļ����ݴ浵���˳�
	void save_and_exit(string Name);
};