#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* right;
    node* left;
    node(int val){
        data=val;
        right=NULL;
        left=NULL;
    }
};

class Solution{
    bool isTreeEqual(node*root1,node*root2){
        if(root1==NULL || root2==NULL){
            return (root1==root2);
        }
        return ((root1->data==root2->data)&&(isTreeEqual(root1->left,root2->right))&&(isTreeEqual(root1->right,root2->left)));
    }
    public:
    bool isTreeSymmetrical(node*root){
        if(root==NULL){
            return true;
        }
        return isTreeEqual(root->left,root->right);
    }
};

/*
            1
           / \
          3   3
         / \ / \
         5 7 7 5
*/

int main(){
    node*root=new node(1);
    root->left=new node(3);
    root->right=new node(3);
    root->left->left=new node(5);
    root->right->right=new node(5);
    root->left->right=new node(7);
    root->right->left=new node(7);
    Solution obj;
    cout<<obj.isTreeSymmetrical(root)<<endl;
}