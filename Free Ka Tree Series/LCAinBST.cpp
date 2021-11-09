#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node*left;
    node*right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

// We just need to find the point where the things split
class Solution{
    public:
    node*lowestCommonAncestor(node*root,node*p,node*q){
        if(root==NULL){
            return;
        }
        if(root->data<p->data && root->data<q->data){
            return lowestCommonAncestor(root->right,p,q);
        }
        if(root->data>p->data && root->data>q->data){
            return lowestCommonAncestor(root->left,p,q);
        }
        return root;
    }
};