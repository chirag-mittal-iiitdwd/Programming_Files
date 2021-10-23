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

void display(node* head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";\
        temp=temp->next;
    }
    cout<<endl;
}

void reverseTheLinkedList(node*&head){
    node*current=head;
    node*next;
    node*previous=NULL;
    while(current!=NULL){
        next=current->next;
        current->next=previous;
        previous=current;
        current=next;
    }
    head=previous;
}

node* reverseRecurise(node*&head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node*newHead=reverseRecurise(head->next);
    head->next->next=head;
    head->next=NULL;
    return newHead;
}

int main(){
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);

    display(head);
    reverseTheLinkedList(head);
    display(head);
    node* newhead=reverseRecurise(head);
    display(newhead);
}