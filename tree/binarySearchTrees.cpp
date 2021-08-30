// In normal trees the searching takes O(n)
// But in binary search trees it is reduced 
// to log(n)
/*
-----> Three rules
1.  In binary search trees, the left subtree of 
    a node contains only nodes with keys lesser 
    than the node's key
2.  The right subtree of a node contains only 
    nodes with keys hreater than the node's key
3.  The left and right subtree each must also be 
    a binary search tree. There must be no 
    duplicate nodes


            3
           / \
          2   7
         /   / \
        1   5   8
           / \
          4   6
*/
// How to build a binary search tree from array
// Inorder triversal of a binary search tree gives sorted material
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

node* insertAtBST(node *root,int val){
    if(root==NULL){
        // Now this becomes out root
        return new node(val);
    }
    if(val<root->data){
        root->left=insertAtBST(root->left,val);
    }
    else{
        root->right=insertAtBST(root->right,val);
    }
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
    node* root=NULL;
    root=insertAtBST(root,5);
    root =insertAtBST(root,1);
    root=insertAtBST(root,3);
    root=insertAtBST(root,4);
    root=insertAtBST(root,2);
    root=insertAtBST(root,7);
    inorderPrint(root);
}