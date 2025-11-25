#include<iostream>
#include<vector>
using namespace std;

class doublyListNode{
public:
    int data;
    doublyListNode *next,*prev;
    doublyListNode(int x) : data(x),next(NULL),prev(NULL){}
};

doublyListNode* createdoublyLinedlist(vector<int> arr){
    if(arr.empty()){
        return NULL;
    }
    doublyListNode* head=new doublyListNode(arr[0]);
    doublyListNode* cur=head;
    for(int i=1;i<(int)arr.size();i++){
        doublyListNode* newNode=new doublyListNode(arr[i]);
        cur->next=newNode;
        newNode->prev=cur;
        cur=cur->next;
    }
    return head;
}

void printList(doublyListNode* l){
    if(l==NULL) return;
    doublyListNode *tail;
    //正向遍历
    for(doublyListNode* i=l;i!=NULL;i=i->next){
        printf("%d ",i->data);
        if(i->next==NULL){
            tail=i;
        }
    }
    cout<<endl;
    //反向遍历
    for(doublyListNode* i=tail;i!=NULL;i=i->prev){
        printf("%d ",i->data);
    }
    cout<<endl;
}

void insertList(doublyListNode *&h,int i,int e){
    doublyListNode* p=h;
    for(int j=1;j<i;j++){
        p=p->next;
        if(p==NULL) return;
    }
    doublyListNode* newNode=new doublyListNode(e);
    newNode->next=p->next;
    newNode->prev=p;
    p->next->prev=newNode;
    p->next=newNode;
}

void deleteListNode(doublyListNode *&h,int index,int &e){
    if(index<1) return;
    doublyListNode *p=h;
    if(index==1){
        e=h->data;
        h=h->next;
        h->prev=NULL;
        p->next=NULL;
        delete p;
        return;
    }
    else{
        for(int i=1;i<index;i++){
            p=p->next;
        }
        doublyListNode * temp=p->next; 
        e=temp->data;
        p->next=p->next->next;
        p->next->next->prev=p;

        temp->prev=temp->next=NULL;
        delete temp;
    }
    return;
}

int main(){
    doublyListNode* L;
    L = createdoublyLinedlist({1,2,3,4,5});

    insertList(L,2,10);
    printList(L);
    int e;
    deleteListNode(L,1,e);
    printList(L);
}