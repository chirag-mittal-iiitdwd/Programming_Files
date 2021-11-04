#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* right;
    node* left;
    node(int val){
        data=val;
        right=NULL;
        left=NULL;
    }
};

class Solution{
    public:
    void childrenSumProperty(node*&root){
        if(root==NULL) return;
        int child=0;
        if(root->left) child+=root->left->data;
        if(root->right) child+=root->right->data;
        if(child>=root->data) root->data=child;
        else{
            if(root->left) root->left->data=root->data;
            else{
                if(root->right) root->right->data=root->data;
            }
        }
        childrenSumProperty(root->left);
        childrenSumProperty(root->right);
        int tot=0;
        if(root->left) tot+=root->left->data;
        if(root->right) tot+=root->right->data;
        if(root->left || root->right) root->data=tot; 
    }
};

void preorder(node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    node*root=new node(2);
    root->left=new node(35);
    root->left->left=new node(2);
    root->left->right=new node(3);
    root->right=new node(10);
    root->right->right=new node(2);
    root->right->left=new node(5);

    preorder(root);
    cout<<endl;
    Solution ob;
    ob.childrenSumProperty(root);
    preorder(root);
    cout<<endl;
}