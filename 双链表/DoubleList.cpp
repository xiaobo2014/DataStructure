#include "DoubleList.h"

#include <iostream>
using namespace std;


//N个结点的双链表的构建函数 
DoubleList* DoubleList::Create(int N){
	//初始化头结点，头结点保存链表长度 
	DoubleList* head;
	head= new DoubleList;
	head->data = N;
	head->prior = NULL;
	head->next = NULL;
	//pre代表第一个数值结点，tail是需要插入的结点
	//tmp是pre的备份，用于改变当前指针 
	DoubleList* pre,*tail,*tmp;
	pre = new DoubleList;
	int data;
	cout<<"请初始化每个结点的数值："<<endl; 
	//初始化头个数值结点
	cin>>pre->data;
	pre->next = NULL;
	pre->prior = NULL;
	tmp = pre;
	N--;
	//剩余的结点初始化 
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
		
//两个结点的连接函数 
void DoubleList::attach(DoubleList* pre, DoubleList* tail){
	pre->next = tail;
	tail->next = NULL;
	tail->prior = pre; 
} 
		
//双链表的打印函数 
void DoubleList::Print(DoubleList* list){
	int len = list->data;
	DoubleList* head;
	head = list->next;
	for(int i = 0 ; i < len ; i++){
		cout<<head->data<<" ";
		head = head->next;
	}
}
		
//双链表的长度函数 
int DoubleList::GetLength(DoubleList* list){
	return list->data;
}
		
//判断双链表是否为空
bool DoubleList::Isempty(DoubleList* list){
	return this->GetLength(list) == 0;
} 
		
//寻找双链表中第k个结点的函数 
DoubleList* DoubleList::FindKth(DoubleList* list,int index){
	DoubleList* head;
	head = list;
	for(int i = 0 ; i < index ; i++){
		head = head->next;
	}
	return head;
} 
		
//寻找数值为N的结点的下标的函数
int DoubleList::FindN(DoubleList* list,int N){
	//-1表示值为N的结点不存在 
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
		
//在forward结点后插入一个insert结点的函数 
void DoubleList::Insert(DoubleList* forward,DoubleList* insert){
	insert->next = forward->next;
	//当插入位置不在链表尾部时 
	if(forward->next != NULL){
		forward->next->prior = insert;
	} 
	forward->next = insert;
	insert->prior = forward;
} 
		
//双链表的在值为k的结点之后插入函数
DoubleList* DoubleList::Insert_num(DoubleList* list,int num){
	int index = this->FindN(list,num);
	//双链表中不存在值为num的结点的情况 
	if(index == -1){
		cout<<"双链表里没有值为："<<num<<"的结点"<<endl;
		return list;
	}
	return this->Insert_index(list,index+1);
}
		
//双链表的在第k个结点之后插入函数
DoubleList* DoubleList::Insert_index(DoubleList* list,int index){
	cout<<"请初始化结点:"<<endl;
	DoubleList* insert;
	insert = new DoubleList;
	cin>>insert->data;
	//链表为空时 
	if(this->Isempty(list)){
		insert->next = NULL;
		list->next = insert;
		insert->prior = list;
		list->data++;			
		return list;
	}
	//输入下标若大于链表长度，直接插到链表尾部 
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
		
//删除值为num的结点 
DoubleList* DoubleList::Delete_num(DoubleList* list, int num){
	int index = this->FindN(list,num);
	//双链表中不存在值为num的结点的情况 
	if(index == -1){
		cout<<"双链表里没有值为："<<num<<"的结点"<<endl;
		return list;
	}
	return this->Delete_index(list,index+1);
}
		
//删除第index个结点的函数 
DoubleList* DoubleList::Delete_index(DoubleList* list, int index){
	//输入下标若大于链表长度，直接删除链表尾部结点
	index = (index<this->GetLength(list))?index:this->GetLength(list);
	DoubleList* forward = this->FindKth(list,index-1);
	DoubleList* _delete = forward->next;
	this->Delete(forward,_delete);
	list->data--;
	return list;
}
		
//逆转链表
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
		
//链表排序，冒泡排序
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

