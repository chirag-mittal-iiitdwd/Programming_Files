/*
Case 1 : node is a leaf 
        Delete it directly
Case 2 : node has one child
        Replace the node with a child and delete the node
Case 3 : when the node has 2 childs
        Find the inorder successor of the node 
        Replace the node with inorder successor
        Than simply delete
*/
#include"bits/stdc++.h"
using namespace std;
class node{
    public:
    int data;
    node* right;
    node* left;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

// For returning the successor node
node* inorderSucc(node* root){
        node* curr=root;
        while(curr && curr->left){
                curr=curr->left;
        }
        return curr;
}


node* deleteInBST(node* root,int key){
        if(root->data>key){
                root->left=deleteInBST(root->left,key);
        }
        else if(root->data<key){
                root->right=deleteInBST(root->right,key);
        }
        // Till here we have found the node and we have to delete it
        else{
                // Case 1
                if(root->left==NULL){
                        node* temp=root->right;
                        free(root);
                        return temp;
                }  // Case 2
                else if(root->right==NULL){
                        node* temp=root->left;
                        free(root);
                        return temp;
                } // Case 3
                node* temp= inorderSucc(root->right);
                // Swapping the values of successor and node to be deleted
                root->data=temp->data;
                root->right=deleteInBST(root->right,temp->data);
                // than finally deleting the swapped node
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
        node* root=new node(4);
        root->left=new node(2);
        root->left->left=new node(1);
        root->left->right=new node(3);
        root->right=new node(5);
        root->right->right=new node(6);
        /*
                        4
                       / \
                      2   5
                     / \   \
                    1   3   6
        */ 
       inorderPrint(root);cout<<endl;
       root=deleteInBST(root,5);
       inorderPrint(root);
}