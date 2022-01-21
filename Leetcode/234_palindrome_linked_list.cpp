#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007

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
    bool isPalindrome(ListNode* head) {
        string str{""};
        ListNode*temp=head;
        while(temp!=NULL){
            temp=temp->next;
            str+=to_string(temp->val);
        }
        int l=0,r=str.size()-1;
        while(l<=r){
            if(str[l]!=str[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};

class Solution {
    ListNode*reverseHalf(ListNode*head,ListNode*first){
        ListNode*prev=NULL;
        ListNode*cur=head;
        ListNode*next;
        while(prev!=first){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        return prev;
    }
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
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return true;
        }

        int len=length(head);
        int k=len/2;
        int pos=1;
        ListNode*first=head;
        while(k!=pos){
            first=first->next;
            pos++;
        }
        ListNode*second=first->next;
        if(len&1){
            second=second->next;
        }
        first=reverseHalf(head,first);
        
        while(first!=NULL){
            if(first->val!=second->val){
                return false;
            }
            first=first->next;
            second=second->next;
        }
        return true;
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    return 0;
}