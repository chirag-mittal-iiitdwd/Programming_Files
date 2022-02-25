#include<bits/stdc++.h>
using namespace std;

class ListNode{
    public:
    ListNode*next;
    int val;
    ListNode(int data){
        val=data;
        next=NULL;
    }
};

class Solution {
    ListNode*merge(ListNode*part1,ListNode*part2){
        if(part1==NULL){
            return part2;
        }
        if(part2==NULL){
            return part1;
        }

        if(part1->val<part2->val){
            part1->next=merge(part1->next,part2);
            return part1;
        }
        else{
            part2->next=merge(part1,part2->next);
            return part2;
        }
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL){
            return head;
        }
        if(head->next==NULL){
            return head;
        }

        ListNode*pre=head;
        ListNode*p1=head;
        ListNode*p2=head;
        while(p2!=NULL && p2->next!=NULL){
            pre=p1;
            p1=p1->next;
            p2=p2->next->next;
        }
        pre->next=NULL;
        ListNode*part1=sortList(head);
        ListNode*part2=sortList(p1);
        return merge(part1,part2);
    }
};