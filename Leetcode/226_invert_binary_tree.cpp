#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    TreeNode*left;
    TreeNode*right;
    int val;
    TreeNode(int data){
        val=data;
        left=NULL;
        right=NULL;
    }
};

class Solution {
    void helper(TreeNode*&ans,TreeNode*&root){
        if(root==NULL){
            return;
        }
        if(root->left!=NULL){
            ans->right=new TreeNode(root->left->val);
            helper(ans->right,root->left);
        }
        if(root->right!=NULL){
            ans->left=new TreeNode(root->right->val);
            helper(ans->left,root->right);
        }
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        TreeNode*ans=NULL;
        if(root!=NULL){
            ans=new TreeNode(root->val);        
        }
        helper(ans,root);
        return ans;
    }
};

class Solution {
public:
    Solution(){
    ios_base::sync_with_stdio(false);

    }
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        TreeNode*temp=root->left;
        root->left=root->right;
        root->right=temp;
        root->left=invertTree(root->left);
        root->right=invertTree(root->right);

        return root;
    }
};
