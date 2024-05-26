#include "SingleList.h"

#include <iostream>
using namespace std;

int main()
{
	cout << "请输入初始化单链表的长度:" << endl;
	int len;
	SingleList tmp;
	SingleList* list;
	cin >> len;
	list = tmp.Create(len);

	cout << "单链表如下：" << endl;
	tmp.Print(list);
	cout << endl;
	cout << "排序后为:" << endl;
	list = tmp.Sort(list);
	tmp.Print(list);
	cout << endl;

	cout << "请输入初始化单链表的长度:" << endl;
	SingleList* list1;
	cin >> len;
	list1 = tmp.Create(len);
	cout << "第二个单链表如下：" << endl;
	tmp.Print(list1);
	cout << endl;
	cout << "排序后为:" << endl;
	list1 = tmp.Sort(list1);
	tmp.Print(list1);
	cout << endl;

	cout << "合并后链表为:" << endl;
	SingleList* merge_list = tmp.Merge(list, list1);
	tmp.Print(merge_list);
	cout << endl;


	cout << "请输入插入结点的位置：" << endl;
	int index, data;
	cin >> index;
	cout << "插入前单链表如下：" << endl;
	tmp.Print(list);
	cout << endl << "请输入插入结点的数值：" << endl;
	cin >> data;
	list = tmp.Insert(list, index, data);
	cout << "插入后单链表如下：" << endl;
	tmp.Print(list);
	cout << endl;


	cout << "请输入删除结点的位置：" << endl;
	cin >> index;
	cout << "删除前单链表如下：" << endl;
	tmp.Print(list);
	tmp.Deletekth(list, index);
	cout << endl << "删除后单链表如下：" << endl;
	tmp.Print(list);
	cout << endl;

	cout << "请输入删除结点的数值：" << endl;
	cin >> data;
	cout << "删除前单链表如下：" << endl;
	tmp.Print(list);
	tmp.DeleteN(list, data);
	cout << endl << "删除后单链表如下：" << endl;
	tmp.Print(list);
	cout << endl;

	cout << "逆转单链表前,单链表如下：" << endl;
	tmp.Print(list);
	cout << endl << "逆转单链表后,单链表如下：" << endl;
	list = tmp.Reverse(list);
	tmp.Print(list);

	return 0;
}