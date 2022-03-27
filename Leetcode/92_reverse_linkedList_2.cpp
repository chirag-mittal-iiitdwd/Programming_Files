#include<bits/stdc++.h>
using namespace std;

class ListNode{
    public:
    int val;
    ListNode*next;
};

class Solution {
    ListNode*reverse(ListNode*head,ListNode*right,ListNode*rightPlus){
        ListNode*prev=rightPlus;
        ListNode*cur=head;
        ListNode*next;

        while(prev!=right){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        return prev;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right){
            return head;
        }

        left--;
        right--;
        int pos=0;
        ListNode*leftP=NULL;
        ListNode*rightP=NULL;
        ListNode*rightPlus=NULL;
        ListNode*temp=head;
        if(pos==left){
            
        }
        while(temp!=NULL){
            if((pos+1)==left){
                leftP=temp;
            }
            else if(pos==right){
                rightP=temp;
            }
            else if(rightP!=NULL){
                rightPlus=temp;
            }
            pos++;
            temp=temp->next;
        }

    }
};