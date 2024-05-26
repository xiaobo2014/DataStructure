#pragma once

//��ͷ���ĵ������࣬ͷ����ŵ������� 
class SingleList {
private:
	int data;
	SingleList* next;
public:
	//������Ĵ���������β�巨 
	SingleList* Create(int len);

	//��data���õ�tail��, ����tail�е�ָ����뵽prev����
	void attach(SingleList* prev, SingleList* tail, int data);

	//��ȡ����ĳ���
	int getLength(SingleList* list);

	//�жϵ������Ƿ�Ϊ�յĺ��� 
	bool Isempty(SingleList* list);

	//������Ĵ�ӡ����
	void Print(SingleList* list);

	//�ڵ�index�������������ֵΪdata�Ľ��ĺ��� 
	SingleList* Insert(SingleList* list, int index, int data);

	//Ѱ�ҵ�k�����ĺ���,ֻ��������Ϊ�յ���� 
	SingleList* Findkth(SingleList* list, int k);

	//Ѱ����ֵΪN�Ľ��ĺ���
	int FindN(SingleList* list, int N);

	//ɾ����ֵΪN�Ľ��ĺ��� 
	void DeleteN(SingleList* list, int N);

	//ɾ����k�����ĺ���
	void Deletekth(SingleList* list, int k);

	//��ת������
	SingleList* Reverse(SingleList* list);

	//���������������������ϲ����� 
	SingleList* Merge(SingleList* list1, SingleList* list2);

	//��������ð������
	SingleList* Sort(SingleList* list);
};