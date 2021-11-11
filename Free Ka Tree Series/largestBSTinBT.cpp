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

class nodeVal{
    public:
    int maxNode,minNode,maxSize;
    nodeVal(int minNode,int maxNode,int maxSize){
        this->maxNode=maxNode;
        this->minNode=minNode;
        this->maxSize=maxSize;
    }
};

class Solution{
    nodeVal largestBSTHelper(node*root){
        if(root==NULL){
            return nodeVal(INT_MAX,INT_MIN,0);
        }
        auto left=largestBSTHelper(root->left);
        auto right=largestBSTHelper(root->right);
        if(left.maxNode<root->data && root->data<right.minNode){
            return nodeVal(min(root->data,left.minNode),max(root->data,right.maxNode),left.maxSize+right.maxSize+1);
        }
        return nodeVal(INT_MIN,INT_MAX,max(left.maxSize,right.maxSize));
    }
    public:
    int largestBSTsubtree(node*root){
        return largestBSTHelper(root).maxSize;
    }
};