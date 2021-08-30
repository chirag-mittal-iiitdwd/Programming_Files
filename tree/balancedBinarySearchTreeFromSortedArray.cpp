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

node* sortedArray(int arr[],int start,int end){
    if(start>end){
        return NULL;
    }
    int mid=(start+end)/2;
    node* root=new node(arr[mid]);
    sortedArray(arr,start,mid-1);
    sortedArray(arr,mid+1,end);
    return root;
}

void inorderPrint(node* root){
    if(root==NULL){
        return;
    }
    inorderPrint(root);
    cout<<root->data<<" ";
    inorderPrint(root);
}

int main(){
    int arr[]={10,20,30,40,50};
    node* root=sortedArray(arr,0,4);
    inorderPrint(root);
    cout<<endl;
}