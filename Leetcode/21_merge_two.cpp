#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node*next;
    Node(int data){
        val=data;
        next=NULL;
    }
};

class Solution {
public:
    Node* mergeTwoLists(Node* list1, Node* list2) {
        Node*newHead=new Node(-1);
        Node*temp=newHead;
        if(list1==NULL && list2==NULL){
            return newHead->next;
        }
        Node*temp1=list1;
        Node*temp2=list2;
        if(list1!=NULL && list2!=NULL){
        while(temp1->next!=NULL && temp2->next!=NULL){
            if(temp1->val<temp2->val){
                temp->next=new Node(temp1->val);
                temp=temp->next;
                temp1=temp1->next;
            }
            else{
                temp->next=new Node(temp2->val);
                temp=temp->next;
                temp2=temp2->next;
            }
        }}
        while(temp2!=NULL){
            temp->next=new Node(temp2->val);
            temp=temp->next;
            temp2=temp2->next;
        }
        while(temp1!=NULL){
            temp->next=new Node(temp1->val);
            temp=temp->next;
            temp1=temp1->next;
        }
        return newHead->next;
    }
};