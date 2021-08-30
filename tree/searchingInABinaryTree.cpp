/*
        Levels      Nodes
          0    --->   n
          1    --->  n/2
          2    --->  n/4
          3    --->  n/8
          .           .
          .           .
          .           .
          nodes = n, Height = h
          1 + 2 + 2^2 + ..... + 2^(h-1)=n
                  2^(h)-1 = n
                h = log(n+1)
            Time Complexity = O(logn)
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

// Time complexity becomes O(logn)
node* searchInBST(node* root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        return root;
    }
    if(root->data>key){
        return searchInBST(root->left,key);
    } 
    return searchInBST(root->right,key);
}

int main(){
    /*
        ---> Binary search tree
                4
               / \
              2   5
             / \   \
            1   3   6
    */
   node* root=new node(4);
   root->left=new node(2);
   root->left->left=new node(1);
   root->left->right=new node(3);
   root->right=new node(5);
   root->right->right=new node(6);
   if(searchInBST(root,5)==NULL){
       cout<<"does not exists\n";
   }
   else{
       cout<<"exists\n";
   }
}