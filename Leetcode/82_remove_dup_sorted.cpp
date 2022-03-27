#include<bits/stdc++.h>
using namespace std;

class ListNode{
    public:
    int val;
    ListNode*next;
    ListNode(int data){
        val=data;
        next=NULL;
    }
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode*newHead=new ListNode(-101);
        ListNode*newTemp=newHead;
        ListNode*temp=head;

        while(temp!=NULL){
            int cur=temp->val;
            int cnt=0;
            while(temp!=NULL && temp->val==cur){
                cnt++;
                temp=temp->next;
            }
            
            if(cnt==1){
                cout<<"cur : "<<cur<<" cnt : "<<cnt<<endl;
                newTemp->next=new ListNode(cur);
                newTemp=newTemp->next;
            }
        }
        return newHead->next;
    }
};