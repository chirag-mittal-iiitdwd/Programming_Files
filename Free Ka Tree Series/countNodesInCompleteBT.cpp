#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node*right;
    node*left;
    node(int val){
        data=val;
        right=NULL;
        left=NULL;
    }
};

class Solution{
    int findLeftHeight(node*root){
        int height=0;
        while(root){
            height++;
            root=root->left;
        }
        return height;
    }
    int findRightHeight(node*root){
        int height=0;
        while(root){
            height++;
            root=root->right;
        }
        return height;
    }
    public:
    int countNodes(node*root){
        if(root==NULL){
            return 0;
        }
        int lh=findLeftHeight(root);
        int rh=findRightHeight(root);
        if(lh==rh){
            // If left and right heights are equal than simply return 2^h-1, formula for complete binary tree
            return (1<<lh)-1;
        }
        // Else return entire height
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};

/*
                  1
                /   \
               2     3
             /  \   /  \
            4    5 6   7
           / \  / \  
          8  9 10  11
*/

int main(){
    node*root=new node(1);
    root->left=new node(2);
    root->left->left=new node(4);
    root->left->left->left=new node(8);
    root->left->left->right=new node(9);
    root->left->right=new node(5);
    root->left->right->left=new node(10);
    root->left->right->right=new node(11);
    root->right=new node(3);
    root->right->left=new node(6);
    root->right->right=new node(7);

    Solution obj;
    cout<<obj.countNodes(root);
}