#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node*next;
    Node(int data){
        val=data;
        next=NULL;
    }
};

class Solution {
public:
    Node* insertionSortList(Node* head) {
        Node* newHead = NULL;
        while(head){
            Node* curNode = head;
            head = head->next;
            curNode->next=NULL;
            
            if(newHead == NULL){
                newHead = curNode;
            }
            else if(newHead->val >= curNode->val){
                curNode->next = newHead;
                newHead = curNode;
            }
            else{
                Node* newheadIter = newHead;
                while(newheadIter->next!=NULL){
                    if(curNode->val > newheadIter->val && curNode->val <= newheadIter->next->val){
                        curNode->next = newheadIter->next;
                        newheadIter->next = curNode;
                        break;
                    }
                    newheadIter = newheadIter->next;
                }  
                if(newheadIter->next==NULL){
                    newheadIter->next = curNode;
                }
            }
        }
        return newHead;
    }
};