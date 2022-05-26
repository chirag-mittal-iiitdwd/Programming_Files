#include<bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
    void insertAtHead(ListNode*&head,int val){
        ListNode*n=new ListNode(val);
        n->next=head;
        head=n;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*>st1;
        stack<ListNode*>st2;

        ListNode*temp=l1;
        while(temp!=NULL){
            st1.push(temp);
            temp=temp->next;
        }

        temp=l2;
        while(temp!=NULL){
            st2.push(temp);
            temp=temp->next;
        }

        ListNode*head=NULL;
        int carry=0;
        while(!st1.empty() && !st2.empty()){
            int first=st1.top()->val;
            int second=st2.top()->val;
            st1.pop();
            st2.pop();
            
            int val=first+second+carry;
            carry=val/10;
            insertAtHead(head,val%10);
        }

        while(!st2.empty()){
            int val=st2.top()->val;
            st2.pop();
            val+=carry;
            carry=val/10;

            insertAtHead(head,val%10);
        }

        while(!st1.empty()){
            int val=st1.top()->val;
            st1.pop();
            val+=carry;
            carry=val/10;

            insertAtHead(head,val%10);
        }

        if(carry!=0){
            insertAtHead(head,carry);
        }
        return head;
    }
};