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

void display(node* head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

node* mergeSortedLinkedList(node*head1,node*head2){
    node*newHead=new node(-1);
    node*tempNew=newHead;
    node*temp1=head1;
    node*temp2=head2;
    while(temp2!=NULL && temp1!=NULL){
        if(temp1->data<temp2->data){
            node*n=new node(temp1->data);
            tempNew->next=n;
            temp1=temp1->next;
            tempNew=tempNew->next;
        }
        else{
            node*n=new node(temp2->data);
            tempNew->next=n;
            temp2=temp2->next;
            tempNew=tempNew->next;
        }
    }

    while(temp2!=NULL){
        node*n=new node(temp2->data);
        tempNew->next=n;
        temp2=temp2->next;
        tempNew=tempNew->next;
    }

    while(temp1!=NULL){
        node*n=new node(temp1->data);
        tempNew->next=n;
        temp1=temp1->next;
        tempNew=tempNew->next;
    }
    return newHead->next;
}

int main(){
    node*head1=NULL;
    node*head2=NULL;
    insertAtTail(head1,1);
    insertAtTail(head2,2);
    insertAtTail(head1,3);
    insertAtTail(head2,4);
    insertAtTail(head1,5);
    insertAtTail(head2,6);
    insertAtTail(head1,7);
    insertAtTail(head2,8);
    display(head1);
    display(head2);

    node*newHead=mergeSortedLinkedList(head1,head2);
    display(newHead);
}