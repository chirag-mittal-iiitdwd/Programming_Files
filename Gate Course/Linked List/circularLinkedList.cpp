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

void insertionAtHead(node*&head,int val){
    node*n=new node(val);
    if(head==NULL){
        n->next=n;
        head=n;
        return;
    }
    node*temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
    head=n;
}

void insertAtTail(node*&head,int val){
    if(head==NULL){
        insertionAtHead(head,val);
        return;
    }
    node*n=new node(val);
    node*temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
}

void deleteAtHead(node*&head){
    if(head==NULL){
        return;
    }
    node*toDelete=head;
    node*temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=temp->next->next;
    temp=temp->next;
    delete head;
    head=temp;
}

void deleteAtTail(node*&head){
    if(head==NULL || head->next==head){
        deleteAtHead(head);
        return;
    }
    node*temp=head;
    while(temp->next->next!=head){
        temp=temp->next;
    }
    node*toDelete=temp->next;
    temp->next=temp->next->next;
    delete toDelete;
}

int lengthOfList(node*head){
    if(head==NULL){
        return 0;
    }
    int cnt=0;
    node*temp=head;
    do{
        cnt++;
        temp=temp->next;
    } while(temp!=head);
    
    return cnt;
}

void deleteAtPosition(node*&head,int pos){
    int length=lengthOfList(head);
    if(pos>=0 && pos<length){
        if(pos==0){
            deleteAtHead(head);
            return;
        }
        else{
            int cnt=0;
            node*temp=head;
            while(pos-1!=cnt){
                temp=temp->next;
                cnt++;
            }
            node*toDelete=temp->next;
            temp->next=temp->next->next;
            delete toDelete;
        }
    }
    else{
        cout<<"Position out of bound exeception"<<endl;
    }   
}

void insertAtPos(node*&head,int val,int pos){
    int length=lengthOfList(head);
    if(pos>=0 && pos<length){
        if(pos==0){
            insertionAtHead(head,val);
            return;
        }
        else{
            node*n=new node(val);
            node*temp=head;
            int cnt=0;
            while(pos-1!=cnt){
                temp=temp->next;
                cnt++;
            }
            n->next=temp->next;
            temp->next=n;
        }
    }
    else{
        cout<<"List out of bound"<<endl;
    }
}

void display(node*head){
    node*temp=head;
    do{
       cout<<temp->data<<" ";
       temp=temp->next;
    } while (temp!=head);
    cout<<endl;
}

int main(){
    node*head=NULL;
    insertionAtHead(head,0);
    insertionAtHead(head,-1);
    insertionAtHead(head,-2);
    display(head);
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    display(head);

    insertAtPos(head,4,4);
    display(head);

    deleteAtPosition(head,4);
    display(head);

    deleteAtHead(head);
    display(head);

    deleteAtTail(head);
    display(head);
}