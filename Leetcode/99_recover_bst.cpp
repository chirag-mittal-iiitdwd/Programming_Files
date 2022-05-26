#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    TreeNode*prev;
    TreeNode*middle;
    TreeNode*second;
    TreeNode*first;
    void inorder(TreeNode*root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        if(prev!=NULL && root->val<prev->val){
            if(first==NULL){
                first=prev;
                middle=root;
            }
            else{
                second=root;
            }
        }
        prev=root;
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        prev=new TreeNode(INT_MIN);
        middle=NULL,second=NULL,first=NULL;
        inorder(root);
        if(first && second){
            swap(first->val,second->val);
        }
        else{
            swap(first->val,middle->val);
        }
    }
};