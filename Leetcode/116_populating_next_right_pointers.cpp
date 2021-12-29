#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node*right;
    Node*left;
    Node*next;
    Node(int data){
        val=data;
        right=left=next=NULL;
    }
};

class Solution{
    public:
    Node*connect(Node*root){
        if(root==NULL){
            return NULL;
        }
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            Node*cur=q.front();
            q.pop();
            if(cur->left){
                q.push(cur->left);
                cur->left->next=cur->right;
            }
            if(cur->right){
                q.push(cur->right);
                if(cur->next){
                    cur->right->next=cur->next->left;
                }
            }
        }
        return root;
    }
};