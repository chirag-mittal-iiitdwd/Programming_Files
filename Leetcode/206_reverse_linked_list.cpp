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
    ListNode* reverseList(ListNode* head) {
        ListNode*cur=head;
        ListNode*prev=NULL;
        ListNode*next;
        while(cur!=NULL){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        return prev;
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    return 0;
}