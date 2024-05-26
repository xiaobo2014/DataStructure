#include "DoubleList.h"

#include <iostream>
using namespace std;


//N������˫����Ĺ������� 
DoubleList* DoubleList::Create(int N){
	//��ʼ��ͷ��㣬ͷ��㱣�������� 
	DoubleList* head;
	head= new DoubleList;
	head->data = N;
	head->prior = NULL;
	head->next = NULL;
	//pre�����һ����ֵ��㣬tail����Ҫ����Ľ��
	//tmp��pre�ı��ݣ����ڸı䵱ǰָ�� 
	DoubleList* pre,*tail,*tmp;
	pre = new DoubleList;
	int data;
	cout<<"���ʼ��ÿ��������ֵ��"<<endl; 
	//��ʼ��ͷ����ֵ���
	cin>>pre->data;
	pre->next = NULL;
	pre->prior = NULL;
	tmp = pre;
	N--;
	//ʣ��Ľ���ʼ�� 
	while(N--){
		tail = new DoubleList;
		cin>>tail->data;
		this->attach(tmp,tail);
		tmp = tail;
	}
	pre->prior = head;
	head->next = pre;
	return head; 
}
		
//�����������Ӻ��� 
void DoubleList::attach(DoubleList* pre, DoubleList* tail){
	pre->next = tail;
	tail->next = NULL;
	tail->prior = pre; 
} 
		
//˫����Ĵ�ӡ���� 
void DoubleList::Print(DoubleList* list){
	int len = list->data;
	DoubleList* head;
	head = list->next;
	for(int i = 0 ; i < len ; i++){
		cout<<head->data<<" ";
		head = head->next;
	}
}
		
//˫����ĳ��Ⱥ��� 
int DoubleList::GetLength(DoubleList* list){
	return list->data;
}
		
//�ж�˫�����Ƿ�Ϊ��
bool DoubleList::Isempty(DoubleList* list){
	return this->GetLength(list) == 0;
} 
		
//Ѱ��˫�����е�k�����ĺ��� 
DoubleList* DoubleList::FindKth(DoubleList* list,int index){
	DoubleList* head;
	head = list;
	for(int i = 0 ; i < index ; i++){
		head = head->next;
	}
	return head;
} 
		
//Ѱ����ֵΪN�Ľ����±�ĺ���
int DoubleList::FindN(DoubleList* list,int N){
	//-1��ʾֵΪN�Ľ�㲻���� 
	int result = -1;
	DoubleList* prev;
	prev = list;
	int len = this->GetLength(list); 
	for(int i = 0 ; i < len ; i++){
		prev = prev->next;
		if(prev->data == N){
			result = i;
			break;
		}
	}
	return result; 
} 
		
//��forward�������һ��insert���ĺ��� 
void DoubleList::Insert(DoubleList* forward,DoubleList* insert){
	insert->next = forward->next;
	//������λ�ò�������β��ʱ 
	if(forward->next != NULL){
		forward->next->prior = insert;
	} 
	forward->next = insert;
	insert->prior = forward;
} 
		
//˫�������ֵΪk�Ľ��֮����뺯��
DoubleList* DoubleList::Insert_num(DoubleList* list,int num){
	int index = this->FindN(list,num);
	//˫�����в�����ֵΪnum�Ľ������ 
	if(index == -1){
		cout<<"˫������û��ֵΪ��"<<num<<"�Ľ��"<<endl;
		return list;
	}
	return this->Insert_index(list,index+1);
}
		
//˫������ڵ�k�����֮����뺯��
DoubleList* DoubleList::Insert_index(DoubleList* list,int index){
	cout<<"���ʼ�����:"<<endl;
	DoubleList* insert;
	insert = new DoubleList;
	cin>>insert->data;
	//����Ϊ��ʱ 
	if(this->Isempty(list)){
		insert->next = NULL;
		list->next = insert;
		insert->prior = list;
		list->data++;			
		return list;
	}
	//�����±������������ȣ�ֱ�Ӳ嵽����β�� 
	index = (index <= this->GetLength(list))?index:this->GetLength(list);
	DoubleList* forward;
	forward = this->FindKth(list,index);
	this->Insert(forward,insert); 
	list->data++;
	return list;
}
		
void DoubleList::Delete(DoubleList* forward,DoubleList* _delete){
	forward->next = _delete->next;
	if(_delete->next != NULL){
		_delete->next->prior = forward;
	} 
		delete _delete; 
}
		
//ɾ��ֵΪnum�Ľ�� 
DoubleList* DoubleList::Delete_num(DoubleList* list, int num){
	int index = this->FindN(list,num);
	//˫�����в�����ֵΪnum�Ľ������ 
	if(index == -1){
		cout<<"˫������û��ֵΪ��"<<num<<"�Ľ��"<<endl;
		return list;
	}
	return this->Delete_index(list,index+1);
}
		
//ɾ����index�����ĺ��� 
DoubleList* DoubleList::Delete_index(DoubleList* list, int index){
	//�����±������������ȣ�ֱ��ɾ������β�����
	index = (index<this->GetLength(list))?index:this->GetLength(list);
	DoubleList* forward = this->FindKth(list,index-1);
	DoubleList* _delete = forward->next;
	this->Delete(forward,_delete);
	list->data--;
	return list;
}
		
//��ת����
DoubleList* DoubleList::Reverse(DoubleList* list){
	DoubleList* head,*front,*tail,*tag;
	head = list;
	front = list->next;
	tail = front->next;
	front->next = NULL;
	while(tail){
		tag = tail->next;
		tail->next = front;
		front->prior = tail;
		front = tail;
		tail = tag;
	}
	head->next = front;
	front->prior = head;
	return head;
}
		
//��������ð������
DoubleList* DoubleList::Sort(DoubleList* list){
	DoubleList* head,*prev1,*prev2;
	head = list;
	prev1 = list->next;
	while(prev1){
		prev2 = prev1->next;
		while(prev2){
			if(prev1->data > prev2->data){
				prev1->data += prev2->data;
				prev2->data = prev1->data - prev2->data;
				prev1->data -= prev2->data;
			}	
			prev2 = prev2->next;
		}
		prev1 = prev1->next;
	}
	return head;
}

