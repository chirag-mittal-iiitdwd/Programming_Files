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
    bool pointerChecks(ListNode*fast,ListNode*slow){
        if(slow->next!=NULL && fast!=NULL && slow!=NULL && fast->next!=NULL && fast->next->next!=NULL){
            return true;
        }
        return false;
    }
    public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL){
            return NULL;
        }
        ListNode*slow=head;
        ListNode*fast=head;
        
        do{
            if(slow->next==NULL){
                return NULL;
            }
            slow=slow->next;
            if(fast->next==NULL || fast->next->next==NULL){
                return NULL;
            }
            fast=fast->next->next;
        }
        while(pointerChecks(fast,slow) && slow!=fast);
        
        if(slow!=fast){
            return NULL;
        }
        slow=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return fast;
    }
};

int main(){

}


#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007
int32_t main(){
    
    cin.tie(NULL);
    cout.tie(NULL);
    
    return 0;
}