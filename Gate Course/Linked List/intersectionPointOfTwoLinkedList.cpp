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
        cout<<temp->data<<" ";\
        temp=temp->next;
    }
    cout<<endl;
}

void intersect(node*&head1,node*&head2,int pos){
    node*temp1=head1;
    node*temp2=head2;
    while(pos-- && temp1!=NULL){
        temp1=temp1->next;
    }
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=temp1;
}

int findIntersection(node*&head1,node*&head2){
    int l1=lengthOfList(head1);
    int l2=lengthOfList(head2);
    node*ptr1;
    node*ptr2;
    int d=0;
    if(l2>l1){
        d=l2-l1;
        ptr1=head2;
        ptr2=head1;
    }
    else{
        d=l1-l2;
        ptr1=head1;
        ptr2=head2;
    }
    for(int i=0;i<d;i++){
        if(ptr1==NULL){
            return -1;
        }
        ptr1=ptr1->next;
    }

    while(ptr1!=NULL && ptr1!=NULL){
        if(ptr1->next==ptr2->next){
            return ptr1->next->data;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }

    return -1;
}

int main(){
    node*head1=NULL;
    node*head2=NULL;
    insertAtTail(head1,1);
    insertAtTail(head1,2);
    insertAtTail(head1,3);
    insertAtTail(head1,4);
    display(head1);

    insertAtTail(head2,5);
    insertAtTail(head2,6);
    insertAtTail(head2,7);
    insertAtTail(head2,8);
    display(head2);

    intersect(head1,head2,2);
    display(head1);
    display(head2);

    cout<<findIntersection(head1,head2)<<endl;
}