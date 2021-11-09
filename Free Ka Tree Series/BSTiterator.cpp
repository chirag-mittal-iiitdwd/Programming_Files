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

class Solution{
    stack<node*>st;
    void pushAll(node*root){
        while(root!=NULL){
            st.push(root);
            root=root->left;
        }
    }
    public:
    Solution(node*root){
        pushAll(root);
    }
    bool hasNext(){
        return !st.empty();
    }
    int next(){
        node*tmpNode=st.top();
        st.pop();
        pushAll(tmpNode->right);
        return tmpNode->data;
    }
};