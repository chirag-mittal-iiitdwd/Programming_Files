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
    ListNode*reverse2(ListNode*&head){
        ListNode*prev=NULL;
        ListNode*cur=head;
        ListNode*nextptr;
        int cnt=0;
        while(cur!=NULL && cnt<2){
            nextptr=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nextptr;
            cnt++;
        }
        if(nextptr!=NULL){
            head->next=reverse2(nextptr);
        }
        return prev;
    }
public:
    ListNode* swapPairs(ListNode* head) {
        return reverse2(head);
    }
};