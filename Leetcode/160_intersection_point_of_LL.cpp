#include<bits/stdc++.h>
#define ll long long int
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
    int lengthLL(ListNode*head){
        ListNode* temp=head;
        int cnt=0;
        while(temp!=NULL){
            temp=temp->next;
            cnt++;
        }
        return cnt;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int l1=lengthLL(headA);
        int l2=lengthLL(headB);
        ListNode*tempA=headA;
        ListNode*tempB=headB;
        if(l1>l2){
            int diff=l1-l2;
            while(diff--){
                tempA=tempA->next;
            }
        }
        else{
            int diff=l2-l1;
            while(diff--){
                tempB=tempB->next;
            }
        }
        while(tempA!=NULL && tempB!=NULL && tempA!=tempB){
            tempA=tempA->next;
            tempB=tempB->next;
        }
        if(tempA==tempB){
            return tempA;
        }
        return NULL;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    return 0;
}