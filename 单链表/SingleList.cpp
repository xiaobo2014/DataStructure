#include "SingleList.h"

#include <iostream>
using namespace std;


//������Ĵ���������β�巨 
SingleList* SingleList::Create(int len){
    SingleList* prev,*head,*tail;
    head = new SingleList;
    head->data = len;
    head->next = nullptr;
    prev = head;
    if(len == 0){
        return head;
    }
    cout<<"���������������ֵ��"<<endl; 
    while(len--){
        int data;
        tail = new SingleList;
        cin>>data;
        this->attach(prev,tail,data); 
        prev = tail;
    }
    return head;
}

void SingleList::attach(SingleList* prev,SingleList* tail,int data){
    tail->next = nullptr;
    tail->data = data;
    prev->next = tail;
}

int SingleList::getLength(SingleList* list){
    return list->data;
}

//�жϵ������Ƿ�Ϊ�յĺ��� 
bool SingleList::Isempty(SingleList* list){
    return list->data == 0;
}

//������Ĵ�ӡ����
void SingleList::Print(SingleList* list){
    if(list->Isempty(list)){
        cout<<"������Ϊ��"<<endl;
        return;
    }
    int len = list->data;
    SingleList* ptrl = list->next;
    for(int i = 0 ; i < len ; i++){
        cout<<ptrl->data<<" ";  
        ptrl = ptrl->next;
    }
}

//�ڵ�index�������������ֵΪdata�Ľ��ĺ��� 
SingleList* SingleList::Insert(SingleList* list,int index ,int data){
    SingleList* prev = list;
    SingleList* insert;
    insert = new SingleList;
    int len = list->getLength(list);
    //����Ϊ��ʱ,����indexΪ���٣�ֻ�ܲ��ڵ�һ��λ�� 
    if(this->Isempty(list)){
        this->attach(prev,insert,data);
        list->data++;
        return list;
    }
    //��������λ�ô��ڵ���������ֱ�Ӳ嵽ĩβ�� 
    index = (list->data <= index)?list->data:index;
    for(int i = 0 ; i < index ; i++){
        prev = prev->next;
    }
    insert->data = data;
    insert->next = prev->next;
    prev->next = insert;
    list->data++;
    return list;
}

//Ѱ�ҵ�k�����ĺ���,ֻ��������Ϊ�յ���� 
SingleList* SingleList::Findkth(SingleList* list ,int k){
    SingleList* prev;
    prev = list;
    for(int i = 0 ; i < k ; i++){
        prev = prev->next;
    } 
    return prev;
}

//Ѱ����ֵΪN�Ľ��ĺ���
int SingleList::FindN(SingleList* list,int N){
    int result = -1;
    SingleList* prev;
    prev = list;
    int len = this->getLength(list); 
    for(int i = 0 ; i < len ; i++){
        prev = prev->next;
        if(prev->data == N){
            result = i;
            break;
        }
    }
    return result; 
}

//ɾ����ֵΪN�Ľ��ĺ��� 
void SingleList::DeleteN(SingleList* list,int N){
    int index = this->FindN(list,N);
    //��������ֵΪN����� 
    if(index == -1){
        cout<<"������������ֵΪ"<<N<<"�Ľ��"<<endl;
        return;
    }
    this->Deletekth(list,index+1);
}

//ɾ����k�����ĺ���
void SingleList::Deletekth(SingleList* list,int k){
    int len = list->data;
    if(this->Isempty(list)){
        cout<<"������Ϊ���޷�ɾ��"<<endl;
        return; 
    }
    SingleList* del_pre;
    del_pre = this->Findkth(list,k-1);
    del_pre->next = del_pre->next->next;
    list->data--;
}

//��ת������
SingleList* SingleList::Reverse(SingleList* list){
    //������Ϊ��ʱ 
    if(this->Isempty(list)){
        return list;
    }
    SingleList* head,*front,*rear,*tag;
    head = list;                //����ͷ��� 
    //front��rear������ת��tag���ڼ�¼δ��ת������ 
    front = list->next;         
    rear = front->next;
    front->next = nullptr;
    while(rear){
        tag = rear->next;
        rear->next = front;
        front = rear;
        rear = tag;
    }
    head->next = front;
    return head;
}

//���������������������ϲ����� 
SingleList* SingleList::Merge(SingleList* list1,SingleList* list2){
    if(list1 == nullptr){
        return list1;
    }
    if(list2 == nullptr){
        return list2;
    }
    SingleList* list;          //�����ϲ������ͷ��㣬�������������֮�� 
    list = new SingleList;
    list->data = list1->data+list2->data;
    list->next = nullptr;
    SingleList* prev1,*prev2,*tail,*head,*tag;
    prev1 = list1->next;        //ָ��list32�ĵ�һ����㣨���Ǵ�ų��ȵ�ͷ��㣬��ͷ���֮��Ľ�㣩
    prev2 = list2->next;
    head = new SingleList;     //����������Ŀ�ͷ��� 
    tag = head;                 //�����ͷ���ĵ�ַ 
    head->next = nullptr;           
    while(prev1 && prev2){
        tail = new SingleList;
        if(prev1->data <= prev2->data){
            this->attach(head,tail,prev1->data);
            head = tail;
            prev1 = prev1->next;
        }else{
            this->attach(head,tail,prev2->data);
            head = tail;
            prev2 = prev2->next;
        }
    }
    if(prev1){
        head->next = prev1;
    }
    if(prev2){
        head->next = prev2;
    }
    list->next = tag->next;
    return list;                    
}

//��������ð������
SingleList* SingleList::Sort(SingleList* list){
    SingleList* head,*prev1,*prev2;
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


