#include<iostream>
#include<vector>
using namespace std;
//
struct ListNode{
    int data;
    ListNode *next;
    ListNode(int x) : data(x),next(NULL){}
};

ListNode* createLinkList(vector<int> arr){
    if(arr.empty()){
        return nullptr;
    }
    ListNode* head = new ListNode(arr[0]); //无头结点
    ListNode* cur=head;
    for(int i=1;i<(int)arr.size();i++){
        cur->next=new ListNode(arr[i]);
        cur=cur->next;
    }
    return head;
}

void lastNodedelet(ListNode* &l){
    ListNode* p =l;
    while(p->next->next!=NULL){
        p=p->next;
    }
    p->next=NULL;
}

void headNodedelet(ListNode* &l){
    ListNode* old=l;
}

void printList(ListNode *l){
    while(l!=NULL){
        printf("%d ",l->data);
        l=l->next;
    }
}

int main(){
    ListNode* l=createLinkList({1,2,3,4,5});
    headNodedelet(l);
    lastNodedelet(l);
    printList(l);
}