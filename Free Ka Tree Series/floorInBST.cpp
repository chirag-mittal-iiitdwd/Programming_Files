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
    node*n=NULL;
    void floorInBST(node*root,int target){
        if(root==NULL){
            return;
        }
        if(root->data<=target){
            n=root;
        }
        if(root->data>target){
            return floorInBST(root->left,target);
        }
        return floorInBST(root->right,target);
    }
    public:
    node*floorBST(node*root,int target){
        floorInBST(root,target);
        return n;
    }
};

int main(){
    node*root=new node(10);
    root->left=new node(5);
    root->left->left=new node(3);
    root->left->left->left=new node(2);
    root->left->left->right=new node(4);
    root->left->right=new node(6);
    root->left->right->right=new node(9);
    root->right=new node(13);
    root->right->right=new node(14);
    root->right->left=new node(11);

    Solution obj;
    cout<<obj.floorBST(root,8)->data<<endl;
}