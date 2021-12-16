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
    int length(ListNode*head){
        int len=0;
        ListNode*temp=head;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        return len;
    }

    ListNode*helper(ListNode*head,int k,int left){
        if(head==NULL){
            return NULL;
        }
        static 
        ListNode*prev=NULL;
        ListNode*cur=head;
        ListNode*nextptr;
        int cnt=0;
        while(cur!=NULL && cnt<k){
            nextptr=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nextptr;
            cnt++;
        }
        if(nextptr!=NULL){
            head->next=helper(nextptr,k);
        }
        return prev;
    }

    public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
    }
};