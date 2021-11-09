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
    public:
    node*insert(node*&root,int val){
        if(root==NULL){
            return new node(val);
        }
        node*cur=root;
        while(true){
            if(cur->data<=val){
                if(cur->right!=NULL){
                    cur=cur->right;
                }
                else{
                    cur->right=new node(val);
                    break;
                }
            }
            else{
                if(cur->left!=NULL){
                    cur=cur->left;
                }
                else{
                    cur->left=new node(val);
                    break;
                }
            }
        }
        return root;
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
    node*root=new node(6);
    root->left=new node(3);
    root->left->left=new node(2);
    root->left->right=new node(4);
    root->right=new node(8);
    root->right->left=new node(7);
    inorder(root);cout<<endl;
    Solution obj;
    node*roo=obj.insert(root,1);
    inorder(roo);cout<<endl;
}