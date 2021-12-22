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
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL){
            return;
        }
        stack<ListNode*>st;
        ListNode*temp=head;
        while(temp!=NULL){
            st.push(temp);
            temp=temp->next;
        }
        int s=st.size();

        ListNode*newHead=head;
        temp=head;
        for(int i=0;i<s/2;i++){
            ListNode*cur=st.top();
            st.pop();
            cur->next=temp->next;
            temp->next=cur;
            temp=temp->next->next;
        }
        temp->next=NULL;
    }
};