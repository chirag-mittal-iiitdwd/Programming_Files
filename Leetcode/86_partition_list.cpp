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
    ListNode* partition(ListNode* head, int x) {
        ListNode*fHead=new ListNode(0);
        ListNode*sHead=new ListNode(0);
        ListNode*fTail=fHead;
        ListNode*sTail=sHead;

        ListNode*temp=head;
        
        while(temp!=NULL){
            if(temp->val<x){
                fTail->next=temp;
                fTail=fTail->next;
            }
            else{
                sTail->next=temp;
                sTail=sTail->next;
            }
            temp=temp->next;
        }
        sTail->next=NULL;
        fTail->next=sHead->next;
        return fHead->next;
    }
};