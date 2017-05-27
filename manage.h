#pragma once
#include<list>
#include"Goods.h"

using namespace std;

class manage {
private:
	list<Goods> goodsInfo;
	list<Goods>::iterator match(char name[]);
public:
	//自动进货
	void add_goods(char name[], int count);
	//自动出货
	void delete_goods(char name[], int count);
	//显示当前库存
	void show_goods();
	//查看仓库中的name商品
	void find_goods(char name[]);

	void empty();
	//进行文件数据读取
	void read(string Name);
	//进行文件数据存档并退出
	void save_and_exit(string Name);
};