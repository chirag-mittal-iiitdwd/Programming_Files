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

void deleteAtHead(node*&head){
    node*toDelete=head;
    head=head->next;
    delete toDelete;
}

void deleteAtTail(node*&head){
    if(head->next==NULL){
        deleteAtHead(head);
        return;
    }
    if(head==NULL){
        return;
    }
    node*temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    node*toDelete=temp->next;
    temp->next=temp->next->next;
    delete toDelete;
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

void deleteAtAposition(node*&head,int pos){
    int length=lengthOfList(head);
    if(pos<length && pos>=0){
        if(pos==0){
            deleteAtHead(head);
            return;
        }
        else{
            node* temp=head;
            int cnt=0;
            while(pos-1!=cnt){
                temp=temp->next;
                cnt++;
            }
            node*toDelete=temp->next;
            temp->next=temp->next->next;
            delete toDelete;

        }
    }
}

void insertAtSomePoint(node*&head,int pos,int key){
    int length=lengthOfList(head);
    if(pos<=length && pos>=0){
        if(pos==0){
            insertAtHead(head,key);
            return;
        }
        else if(pos==length){
            insertAtTail(head,key);
            return;
        }
        else{
            node*n=new node(key);
            int cnt=0;
            node* temp=head;
            while(pos-1!=cnt){
                cnt++;
                temp=temp->next;
            }
            n->next=temp->next;
            temp->next=n;
        }
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
    insertAtSomePoint(head,4,7);
    display(head);

    deleteAtHead(head);
    display(head);
    deleteAtTail(head);
    display(head);
    deleteAtAposition(head,3);

    display(head);
}