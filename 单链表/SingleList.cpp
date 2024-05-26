#include "SingleList.h"

#include <iostream>
using namespace std;


//单链表的创建函数，尾插法 
SingleList* SingleList::Create(int len){
    SingleList* prev,*head,*tail;
    head = new SingleList;
    head->data = len;
    head->next = nullptr;
    prev = head;
    if(len == 0){
        return head;
    }
    cout<<"请输入各个结点的数值："<<endl; 
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

//判断单链表是否为空的函数 
bool SingleList::Isempty(SingleList* list){
    return list->data == 0;
}

//单链表的打印函数
void SingleList::Print(SingleList* list){
    if(list->Isempty(list)){
        cout<<"单链表为空"<<endl;
        return;
    }
    int len = list->data;
    SingleList* ptrl = list->next;
    for(int i = 0 ; i < len ; i++){
        cout<<ptrl->data<<" ";  
        ptrl = ptrl->next;
    }
}

//在第index个结点后面插入数值为data的结点的函数 
SingleList* SingleList::Insert(SingleList* list,int index ,int data){
    SingleList* prev = list;
    SingleList* insert;
    insert = new SingleList;
    int len = list->getLength(list);
    //链表为空时,无论index为多少，只能插在第一个位置 
    if(this->Isempty(list)){
        this->attach(prev,insert,data);
        list->data++;
        return list;
    }
    //如果插入的位置大于等于链表长度直接插到末尾， 
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

//寻找第k个结点的函数,只适用链表不为空的情况 
SingleList* SingleList::Findkth(SingleList* list ,int k){
    SingleList* prev;
    prev = list;
    for(int i = 0 ; i < k ; i++){
        prev = prev->next;
    } 
    return prev;
}

//寻找数值为N的结点的函数
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

//删除数值为N的结点的函数 
void SingleList::DeleteN(SingleList* list,int N){
    int index = this->FindN(list,N);
    //不存在数值为N的情况 
    if(index == -1){
        cout<<"单链表不存在数值为"<<N<<"的结点"<<endl;
        return;
    }
    this->Deletekth(list,index+1);
}

//删除第k个结点的函数
void SingleList::Deletekth(SingleList* list,int k){
    int len = list->data;
    if(this->Isempty(list)){
        cout<<"单链表为空无法删除"<<endl;
        return; 
    }
    SingleList* del_pre;
    del_pre = this->Findkth(list,k-1);
    del_pre->next = del_pre->next->next;
    list->data--;
}

//逆转链表函数
SingleList* SingleList::Reverse(SingleList* list){
    //单链表为空时 
    if(this->Isempty(list)){
        return list;
    }
    SingleList* head,*front,*rear,*tag;
    head = list;                //保存头结点 
    //front，rear用于逆转，tag用于记录未逆转的链表 
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

//对两个升序链表进行升序合并函数 
SingleList* SingleList::Merge(SingleList* list1,SingleList* list2){
    if(list1 == nullptr){
        return list1;
    }
    if(list2 == nullptr){
        return list2;
    }
    SingleList* list;          //建立合并链表的头结点，存放两个链表长度之和 
    list = new SingleList;
    list->data = list1->data+list2->data;
    list->next = nullptr;
    SingleList* prev1,*prev2,*tail,*head,*tag;
    prev1 = list1->next;        //指向list32的第一个结点（不是存放长度的头结点，即头结点之后的结点）
    prev2 = list2->next;
    head = new SingleList;     //建立新链表的空头结点 
    tag = head;                 //保存空头结点的地址 
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

//链表排序，冒泡排序
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


