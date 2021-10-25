#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node*next;
    node(int val){
        data=val;
        next=NULL;
    }
};

void insertAtHead(node*&head,int val){
    node* n=new node(val);
    n->next=head;
    head=n;
}

void insertAtTail(node*&head,int val){
    if(head==NULL){
        insertAtHead(head,val);
        return;
    }
    node* n=new node(val);
    node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

int lengthOfList(node*head){
    int cnt=0;
    node*temp=head;
    while(temp!=NULL){
        temp=temp->next;
        cnt++;
    }
    return cnt;
}

void appendLastKnodes(node*&head,int k){
    int length=lengthOfList(head);
    if(k<=length && k>0){
        int x=length-k;
        int cnt=0;
        node*temp=head;
        node*change;
        while(temp->next!=NULL){
            if(x-1==cnt){
                change=temp;
            }
            temp=temp->next;
            cnt++;
        }
        temp->next=head;
        head=change->next;
        change->next=NULL;
    }
}

void display(node* head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";\
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    node* head=NULL;
    insertAtHead(head,0);
    insertAtHead(head,-1);
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    display(head);
    appendLastKnodes(head,2);
    display(head);
}