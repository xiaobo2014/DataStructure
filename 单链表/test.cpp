#include "SingleList.h"

#include <iostream>
using namespace std;

int main()
{
	cout << "�������ʼ��������ĳ���:" << endl;
	int len;
	SingleList tmp;
	SingleList* list;
	cin >> len;
	list = tmp.Create(len);

	cout << "���������£�" << endl;
	tmp.Print(list);
	cout << endl;
	cout << "�����Ϊ:" << endl;
	list = tmp.Sort(list);
	tmp.Print(list);
	cout << endl;

	cout << "�������ʼ��������ĳ���:" << endl;
	SingleList* list1;
	cin >> len;
	list1 = tmp.Create(len);
	cout << "�ڶ������������£�" << endl;
	tmp.Print(list1);
	cout << endl;
	cout << "�����Ϊ:" << endl;
	list1 = tmp.Sort(list1);
	tmp.Print(list1);
	cout << endl;

	cout << "�ϲ�������Ϊ:" << endl;
	SingleList* merge_list = tmp.Merge(list, list1);
	tmp.Print(merge_list);
	cout << endl;


	cout << "������������λ�ã�" << endl;
	int index, data;
	cin >> index;
	cout << "����ǰ���������£�" << endl;
	tmp.Print(list);
	cout << endl << "��������������ֵ��" << endl;
	cin >> data;
	list = tmp.Insert(list, index, data);
	cout << "������������£�" << endl;
	tmp.Print(list);
	cout << endl;


	cout << "������ɾ������λ�ã�" << endl;
	cin >> index;
	cout << "ɾ��ǰ���������£�" << endl;
	tmp.Print(list);
	tmp.Deletekth(list, index);
	cout << endl << "ɾ�����������£�" << endl;
	tmp.Print(list);
	cout << endl;

	cout << "������ɾ��������ֵ��" << endl;
	cin >> data;
	cout << "ɾ��ǰ���������£�" << endl;
	tmp.Print(list);
	tmp.DeleteN(list, data);
	cout << endl << "ɾ�����������£�" << endl;
	tmp.Print(list);
	cout << endl;

	cout << "��ת������ǰ,���������£�" << endl;
	tmp.Print(list);
	cout << endl << "��ת�������,���������£�" << endl;
	list = tmp.Reverse(list);
	tmp.Print(list);

	return 0;
}