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
    vector<int>nodes;
    Solution(ListNode* head) {
        ListNode*temp=head;
        while(temp!=NULL){
            nodes.push_back(temp->val);
            temp=temp->next;
        }
    }
    
    int getRandom() {
        int size=nodes.size();
        int idx = rand()%size;
        return nodes[idx];
    }
};