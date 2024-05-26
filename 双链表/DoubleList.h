#pragma once

#include <iostream>
using namespace std;

class DoubleList {
private:
	int data;
	DoubleList* next;
	DoubleList* prior;
public:
	//N������˫����Ĺ������� 
	DoubleList* Create(int N);

	//�����������Ӻ��� 
	void attach(DoubleList* pre, DoubleList* tail);

	//˫����Ĵ�ӡ���� 
	void Print(DoubleList* list);

	//˫����ĳ��Ⱥ��� 
	int GetLength(DoubleList* list);

	//�ж�˫�����Ƿ�Ϊ��
	bool Isempty(DoubleList* list);

	//Ѱ��˫�����е�k�����ĺ��� 
	DoubleList* FindKth(DoubleList* list, int index);

	//Ѱ����ֵΪN�Ľ����±�ĺ���
	int FindN(DoubleList* list, int N);

	//��forward�������һ��insert���ĺ��� 
	void Insert(DoubleList* forward, DoubleList* insert);

	//˫�������ֵΪk�Ľ��֮����뺯��
	DoubleList* Insert_num(DoubleList* list, int num);

	//˫������ڵ�k�����֮����뺯��
	DoubleList* Insert_index(DoubleList* list, int index);

	void Delete(DoubleList* forward, DoubleList* _delete);

	//ɾ��ֵΪnum�Ľ�� 
	DoubleList* Delete_num(DoubleList* list, int num);

	//ɾ����index�����ĺ��� 
	DoubleList* Delete_index(DoubleList* list, int index);

	//��ת����
	DoubleList* Reverse(DoubleList* list);

	//��������ð������
	DoubleList* Sort(DoubleList* list);
};
