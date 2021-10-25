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
    if(head!=NULL){
        head->prev=n;
    }
    head=n;
}

void insertAtTail(node*&head,int val){
    if(head==NULL){
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
    head=head->next;
    // head->next=NULL;
    delete teoDelete;
}

void deleteAtTail(node*&head){
    if(head==NULL || head->next==NULL){
        deleteAtHead(head);
        return;
    }
    node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    node*toDelete=temp->next;
    temp->next=NULL;
    delete toDelete;
}

void display(node*head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    node*head=NULL;
    insertAtHead(head,1);
    insertAtHead(head,0);
    display(head);

    insertAtTail(head,3);
    insertAtTail(head,4);
    display(head);

    deleteAtHead(head);
    display(head);

    deleteAtTail(head);
    display(head);
}