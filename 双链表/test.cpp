#include "DoubleList.h"

#include <iostream>
using namespace std;


int main()
{
	DoubleList tmp;
	DoubleList* list;
	int len, index, num;
	cout << "���ʼ��˫����ĳ��ȣ�" << endl;
	cin >> len;
	list = tmp.Create(len);
	list = tmp.Sort(list);
	cout << "˫����Ϊ��" << endl;
	tmp.Print(list);
	cout << endl;

	cout << "����ǰ˫����Ϊ��" << endl;
	tmp.Print(list);
	cout << endl << "��������Ҫ����֮�����������:" << endl;
	cin >> index;
	list = tmp.Insert_index(list, index);
	cout << "�����˫����Ϊ��" << endl;
	tmp.Print(list);
	cout << endl;

	cout << "����ǰ˫����Ϊ��" << endl;
	tmp.Print(list);
	cout << endl << "��������Ҫ����֮����������ֵ:" << endl;
	cin >> num;
	list = tmp.Insert_num(list, num);
	cout << "�����˫����Ϊ��" << endl;
	tmp.Print(list);
	cout << endl;

	cout << "ɾ��ǰ˫����Ϊ��" << endl;
	tmp.Print(list);
	cout << endl << "��������Ҫ����֮��ɾ���������:" << endl;
	cin >> index;
	list = tmp.Delete_index(list, index);
	cout << "ɾ����˫����Ϊ��" << endl;
	tmp.Print(list);
	cout << endl;

	cout << "ɾ��ǰ˫����Ϊ��" << endl;
	tmp.Print(list);
	cout << endl << "��������Ҫ����֮��ɾ��������ֵ:" << endl;
	cin >> num;
	list = tmp.Delete_num(list, num);
	cout << "ɾ����˫����Ϊ��" << endl;
	tmp.Print(list);
	cout << endl;

	cout << "��ת˫��������ǰ,˫�������£�" << endl;
	tmp.Print(list);
	cout << endl << "��ת˫�����,˫�������£�" << endl;
	list = tmp.Reverse(list);
	tmp.Print(list);

	return 0;
}
