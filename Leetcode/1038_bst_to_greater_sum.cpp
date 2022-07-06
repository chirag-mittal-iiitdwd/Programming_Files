#include<bits/stdc++.h>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
    int findSum(TreeNode*root){
        if(root==NULL){
            return 0;
        }
        return root->val+findSum(root->left)+findSum(root->right);
    }

    void nodeMinusSmallVals(TreeNode*root,int&smallSum,int&sum){
        if(root==NULL){
            return;
        }
        nodeMinusSmallVals(root->left,smallSum,sum);
        int prevNodeVal=root->val;
        root->val=(sum-smallSum);
        smallSum+=prevNodeVal;
        nodeMinusSmallVals(root->right,smallSum,sum);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        int sum=findSum(root);
        int smallSum=0;
        nodeMinusSmallVals(root,smallSum,sum);
        return root;
    }
};

class Solution {
    int sum=0;
public:
    TreeNode* bstToGst(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        bstToGst(root->right);
        sum+=root->val;
        root->val=sum;
        bstToGst(root->left);
        return root;
    }
};