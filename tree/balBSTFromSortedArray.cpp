/*
----> Algorithm
1. MAke the middle element the root
2. Recursively, do the same for subtrees
    a. start to mid-1 for left subtree
    b. mid+1 to end for right subtree
*/

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

node* sortedArrayToBST(int arr[],int start,int end){
    if(start>end){
        return NULL;
    }
    int mid=(start+end)/2;
    node* root=new node(arr[mid]);
    root->left=sortedArrayToBST(arr,start,mid-1);
    root->right=sortedArrayToBST(arr,mid+1,end);
    return root;
}

void inorderPrint(node* root){
    if(root==NULL){
        return;
    }
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

int main(){
    int arr[]={10,20,30,40,50};
    node* root=sortedArrayToBST(arr,0,4);
    inorderPrint(root);
    cout<<endl;
}