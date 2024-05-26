#include "DoubleList.h"

#include <iostream>
using namespace std;


int main()
{
	DoubleList tmp;
	DoubleList* list;
	int len, index, num;
	cout << "请初始化双链表的长度：" << endl;
	cin >> len;
	list = tmp.Create(len);
	list = tmp.Sort(list);
	cout << "双链表为：" << endl;
	tmp.Print(list);
	cout << endl;

	cout << "插入前双链表为：" << endl;
	tmp.Print(list);
	cout << endl << "请输入需要在其之后插入结点的序号:" << endl;
	cin >> index;
	list = tmp.Insert_index(list, index);
	cout << "插入后双链表为：" << endl;
	tmp.Print(list);
	cout << endl;

	cout << "插入前双链表为：" << endl;
	tmp.Print(list);
	cout << endl << "请输入需要在其之后插入结点的数值:" << endl;
	cin >> num;
	list = tmp.Insert_num(list, num);
	cout << "插入后双链表为：" << endl;
	tmp.Print(list);
	cout << endl;

	cout << "删除前双链表为：" << endl;
	tmp.Print(list);
	cout << endl << "请输入需要在其之后删除结点的序号:" << endl;
	cin >> index;
	list = tmp.Delete_index(list, index);
	cout << "删除后双链表为：" << endl;
	tmp.Print(list);
	cout << endl;

	cout << "删除前双链表为：" << endl;
	tmp.Print(list);
	cout << endl << "请输入需要在其之后删除结点的数值:" << endl;
	cin >> num;
	list = tmp.Delete_num(list, num);
	cout << "删除后双链表为：" << endl;
	tmp.Print(list);
	cout << endl;

	cout << "逆转双链表链表前,双链表如下：" << endl;
	tmp.Print(list);
	cout << endl << "逆转双链表后,双链表如下：" << endl;
	list = tmp.Reverse(list);
	tmp.Print(list);

	return 0;
}
