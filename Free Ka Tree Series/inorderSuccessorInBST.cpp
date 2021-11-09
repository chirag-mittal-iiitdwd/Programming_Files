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
    node*successor=NULL;
    node*inorderSuccessor(node*root,int val){
        if(root==NULL){
            return NULL;
        }
        if(root->data>val){
            successor=root;
            return inorderSuccessor(root->left,val);
        }
        else{
            return inorderSuccessor(root->right,val);
        }
    }
    public:
    node*inOrderSuccessor(node*root,int val){
        inorderSuccessor(root,val);
        return successor;
    }
};

// class Solution {
// public:
//     TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
//         TreeNode* successor = NULL;
        
//         while (root != NULL) {
            
//             if (p->val >= root->val) {
//                 root = root->right;
//             } else {
//                 successor = root;
//                 root = root->left;
//             }
//         }
        
//         return successor;
//     }
// };

int main(){
    node*root=new node(5);
    root->left=new node(3);
    root->left->left=new node(2);
    root->left->left->left=new node(1);
    root->left->right=new node(4);
    root->right=new node(7);
    root->right->right=new node(9);
    root->right->right->right=new node(10);
    root->right->left=new node(6);
    root->right->right->left=new node(8);

    Solution obj;
    cout<<obj.inOrderSuccessor(root,8)->data;
}