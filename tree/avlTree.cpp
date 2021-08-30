#include<iostream>
using namespace std;
class node{
    public:
    node* right;
    int data;
    node* left;
    int height;
    node(int val){
        left=NULL;
        right=NULL;
        data=val;
    }
};

node* insertInBST(node* root,int value){
    if(root==NULL){
        node* n=new node(value);
        n->height=1;
        return n;
    }
    if(value>root->data){
        root->right=insertInBST(root->right,value);
    }
    else{
        root->left=insertInBST(root->left,value);
    }
    return root;
}