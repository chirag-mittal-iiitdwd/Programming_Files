#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int data)
    {
        val = data;
        next = NULL;
    }
};

class Solution{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right){
        if (head == NULL || head->next == NULL){
            return head;
        }

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* it = dummy;
        ListNode* prevIt = NULL;

        for (int i = 0; i < left; i++){
            prevIt = it;
            it = it->next;
        }

        ListNode* itR = it;
        ListNode* prevR = prevIt;
        for (int i = left; i <= right; i++){
            ListNode* forward = itR->next;
            itR->next = prevR;
            prevR = itR;
            itR = forward;
        }

        prevIt->next = prevR;
        it->next = itR;

        return dummy->next;
    }
};