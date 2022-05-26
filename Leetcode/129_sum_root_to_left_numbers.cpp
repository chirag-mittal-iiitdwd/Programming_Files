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
    bool isLeaf(TreeNode*root){
        if(root!=NULL && root->left==NULL && root->right==NULL){
            return true;
        }
        return false;
    }
    void helper(TreeNode*root,int curSum,int&ans,int i){
        if(isLeaf(root)){
            ans+=curSum;
            return;
        }

        if(root->left!=NULL){
            helper(root->left,curSum+(root->left->val*i),ans,i*10);
        }
        if(root->right!=NULL){
            helper(root->right,curSum+(root->right->val*i),ans,i*10);
        }
    }
public:
    int sumNumbers(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        if(isLeaf(root)){
            return root->val;
        }
        int ans=0,curSum=0,pow10=10;
        curSum+=root->val;
        helper(root,curSum,ans,pow10);
        return ans;
    }
};