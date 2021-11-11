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
    node*first;
    node*prev;
    node*middle;
    node*last;
    void inorder(node*&root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        if(prev!=NULL && root->data<prev->data){
            if(first==NULL){
                first=prev;
                middle=root;
            }
            else{
                last=root;
            }
        }
        prev=root;
        inorder(root->right);
    }
    public:
    void recoverBST(node*&root){
        first=middle=last=NULL;
        prev=new node(INT_MIN);
        inorder(root);
        if(first&&last){
            swap(first->data,last->data);
        }
        else if(!first && !middle && !last){
            return;
        }
        else if(first&&middle){
            swap(middle->data,first->data);
        }
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
    node*root=new node(7);
    root->left=new node(3);
    root->left->left=new node(2);
    root->left->left->left=new node(1);
    root->left->right=new node(6);
    root->left->right->left=new node(5);
    root->left->right->left->left=new node(4);
    root->right=new node(10);
    root->right->right=new node(11);
    root->right->left=new node(9);
    root->right->left->left=new node(8);
    inorder(root);cout<<endl;
    Solution obj;
    obj.recoverBST(root);
    inorder(root);
}