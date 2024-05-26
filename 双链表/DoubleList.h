#pragma once

#include <iostream>
using namespace std;

class DoubleList {
private:
	int data;
	DoubleList* next;
	DoubleList* prior;
public:
	//N个结点的双链表的构建函数 
	DoubleList* Create(int N);

	//两个结点的连接函数 
	void attach(DoubleList* pre, DoubleList* tail);

	//双链表的打印函数 
	void Print(DoubleList* list);

	//双链表的长度函数 
	int GetLength(DoubleList* list);

	//判断双链表是否为空
	bool Isempty(DoubleList* list);

	//寻找双链表中第k个结点的函数 
	DoubleList* FindKth(DoubleList* list, int index);

	//寻找数值为N的结点的下标的函数
	int FindN(DoubleList* list, int N);

	//在forward结点后插入一个insert结点的函数 
	void Insert(DoubleList* forward, DoubleList* insert);

	//双链表的在值为k的结点之后插入函数
	DoubleList* Insert_num(DoubleList* list, int num);

	//双链表的在第k个结点之后插入函数
	DoubleList* Insert_index(DoubleList* list, int index);

	void Delete(DoubleList* forward, DoubleList* _delete);

	//删除值为num的结点 
	DoubleList* Delete_num(DoubleList* list, int num);

	//删除第index个结点的函数 
	DoubleList* Delete_index(DoubleList* list, int index);

	//逆转链表
	DoubleList* Reverse(DoubleList* list);

	//链表排序，冒泡排序
	DoubleList* Sort(DoubleList* list);
};
