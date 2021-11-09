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

/*
    Basic Strategy : Take the node which we want to delete than connect its right to the 
    rightmost node of left subtree
*/

class Solution{
    node*lastRightOfLeft(node*root){
        if(root->right==NULL){
            return root;
        }
        return lastRightOfLeft(root->right);
    }
    node*makeNecessaryConnections(node*root){
        if(root->left==NULL){
            delete root->left;
            return root->right;
        }
        else if(root->right==NULL){
            delete root->right;
            return root->left;
        }
        else{
            node*rightChild=root->right;
            node*extremeRightOfLeft=lastRightOfLeft(root->left);
            extremeRightOfLeft->right=rightChild;
            return root->left;
        }
    }
    public:
    node*deleteNode(node*root,int key){
        if(root==NULL){
            return NULL;
        }
        if(root->data==key){
            return makeNecessaryConnections(root);
        }
        node*dummy=root;
        while(root!=NULL){
            if(root->data>key){
                if(root->left!=NULL && root->left->data==key){
                    root->left=makeNecessaryConnections(root->left);
                    break;
                }
                else{
                    root=root->left;
                }
            }
            else{
                if(root->right!=NULL && root->right->data==key){
                    root->right=makeNecessaryConnections(root->right);
                    break;
                }
                else{
                    root=root->right;
                }
            }
        }
        return dummy;
    }
};

void inorder(node*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    node*root=new node(8);
    root->left=new node(5);
    root->left->left=new node(2);
    root->left->left->left=new node(1);
    root->left->right=new node(7);
    root->left->right->left=new node(6);
    root->left->right->right=new node(8);
    root->left->left->right=new node(3);
    root->left->left->right=new node(4);
    root->right=new node(12);
    root->right->right=new node(13);
    root->right->left=new node(10);

    inorder(root);cout<<endl;

    Solution obj;
    node*n=obj.deleteNode(root,5);

    inorder(n);cout<<endl;
}