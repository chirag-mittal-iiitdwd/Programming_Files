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
    ListNode* middleNode(ListNode* head) {
        stack<ListNode*>st;
        ListNode*temp=head;
        while(temp!=NULL){
            st.push(temp);
            temp=temp->next;
        }

        ListNode*left=head;
        ListNode*right=st.top();
        while(left!=right && left->next!=right){
            left=left->next;
            st.pop();
            right=st.top();
        }
        return right;
    }
};