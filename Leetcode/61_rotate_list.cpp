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
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int len=length(head);
        k=k%len;
        if(k==0){
            return head;
        }

        ListNode*temp=head;
        int cnt=0,toGo=len-k-1;  // toGo= 5 - 1 -1 = 3
        while(toGo>cnt){
            temp=temp->next;
            cnt++;
        }

        ListNode*toAttachAtFirst=temp->next;
        temp->next=NULL;

        ListNode*lastOfbreak=toAttachAtFirst;
        while(lastOfbreak->next!=NULL){
            lastOfbreak->next;
        }

        lastOfbreak->next=head;
        head=toAttachAtFirst;
        return head;
    }
};