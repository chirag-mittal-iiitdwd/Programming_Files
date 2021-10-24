#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node*next;
    node*prev;
    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};

void insertAtHead(node*&head,int val){
    node* n=new node(val);
    n->next=head;
    head->prev=n;
}

void insertAtTail(node*&head,int val){
    if(head=NULL){
        insertAtHead(head,val);
        return;
    }
    node*n=new node(val);
    node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}

void deleteAtHead(node*&head){
    if(head==NULL){
        return;
    }
    node*teoDelete=head;
    head->next->prev=NULL;
    // head->next=NULL;
    delete teoDelete;
}

void deleteAtTail(node*&head){
    if(head==NULL || head->next==NULL){
        deleteAtHead(head);
        return;
    }
    
}