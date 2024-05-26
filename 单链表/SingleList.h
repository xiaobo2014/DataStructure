#pragma once

//带头结点的单链表类，头结点存放单链表长度 
class SingleList {
private:
	int data;
	SingleList* next;
public:
	//单链表的创建函数，尾插法 
	SingleList* Create(int len);

	//将data设置到tail中, 并将tail中的指针插入到prev后面
	void attach(SingleList* prev, SingleList* tail, int data);

	//获取数组的长度
	int getLength(SingleList* list);

	//判断单链表是否为空的函数 
	bool Isempty(SingleList* list);

	//单链表的打印函数
	void Print(SingleList* list);

	//在第index个结点后面插入数值为data的结点的函数 
	SingleList* Insert(SingleList* list, int index, int data);

	//寻找第k个结点的函数,只适用链表不为空的情况 
	SingleList* Findkth(SingleList* list, int k);

	//寻找数值为N的结点的函数
	int FindN(SingleList* list, int N);

	//删除数值为N的结点的函数 
	void DeleteN(SingleList* list, int N);

	//删除第k个结点的函数
	void Deletekth(SingleList* list, int k);

	//逆转链表函数
	SingleList* Reverse(SingleList* list);

	//对两个升序链表进行升序合并函数 
	SingleList* Merge(SingleList* list1, SingleList* list2);

	//链表排序，冒泡排序
	SingleList* Sort(SingleList* list);
};