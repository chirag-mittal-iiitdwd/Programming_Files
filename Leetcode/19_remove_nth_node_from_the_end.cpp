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

void insertAtHead(Node*&head,int data){
    Node*n=new Node(data);
    n->next=head;
    head=n;
}

class Solution {
    void insertAtHead(Node*&head,int data){
        Node*n=new Node(data);
        n->next=head;
        head=n;
    }
public:
    Node* removeNthFromEnd(Node*&head,int n) {
        vector<int>nos;
        Node*temp=head;
        while(temp!=NULL){
            nos.push_back(temp->val);
            temp=temp->next;
        }
        reverse(nos.begin(),nos.end());
        Node*newHead=NULL;
        int x=nos.size();
        for(int i=1;i<=x;i++){
            if(i==n){
                continue;
            }
            else{
                insertAtHead(newHead,nos[i-1]);
            }
        }
        return newHead;
    }
};

void display(Node*head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    Node*head=NULL;
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    display(head);
    Solution obj;
    Node*newHead=obj.removeNthFromEnd(head,5);
    display(newHead);
}