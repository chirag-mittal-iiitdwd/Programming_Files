#include"bits/stdc++.h"
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

// Time complexity = O(n) n=number of elements int the tree
int calcHeight(node* root){
    if(root==NULL){
        return 0;
    }
    int lHeight=calcHeight(root->left);
    int rHeight=calcHeight(root->right);

    return max(lHeight,rHeight)+1;
}

// Time complexiy = O(n^2) n=number of nodes
int calcDiameter(node* root){
    if(root==NULL){
        return 0;
    }
    int lHeight=calcHeight(root->left);
    int rHeight=calcHeight(root->right);
    int currDiameter=lHeight+rHeight+1;

    int lDiameter=calcDiameter(root->left);
    int rDiameter=calcDiameter(root->right);

    return max(currDiameter,max(lDiameter,rDiameter));
}

// Time Complexity = O(n) n=number of nodes
int clacDiameterOpti(node* root,int &height){
    if(root==NULL){
        height=0;
        return 0;
    }
    int lh=0;
    int rh=0;
    int lDiameter=clacDiameterOpti(root->left,lh);
    int rDiamater=clacDiameterOpti(root->right,rh);
    int currDiameter=lh+rh+1;
    height=max(lh,rh)+1;

    return max(currDiameter,max(lDiameter,rDiamater));
}

int sizeOfBinaryTree(node* root){
    if(root==NULL){
        return 0;
    }
    return sizeOfBinaryTree(root->left)+sizeOfBinaryTree(root->right)+1;
}

int main(){
    /*
            1
           /  \
          2    3
         / \   /\
        4   5 6  7
    */
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);

    cout<<calcHeight(root)<<endl;
    cout<<calcDiameter(root)<<endl;
    int height=0;
    cout<<clacDiameterOpti(root,height)<<endl;
    cout<<sizeOfBinaryTree(root)<<endl;
}