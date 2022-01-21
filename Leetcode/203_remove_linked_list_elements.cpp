#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007

class ListNode{
    public:
    int val;
    ListNode*next;
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL){
            return NULL;
        }
        while(head!=NULL && head->val==val){
            ListNode*toDel=head;
            head=head->next;
            delete toDel;
        }
        ListNode*temp=head;

        while(temp!=NULL && temp->next!=NULL){
            if(temp->next->val==val){
                ListNode*toDel=temp->next;
                temp->next=temp->next->next;
                delete toDel;
            }
            else{
                temp=temp->next;
            }
        }
        return head;
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    return 0;
}