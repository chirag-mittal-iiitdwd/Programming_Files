#include<bits/stdc++.h>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
    TreeNode*helper(TreeNode*root,int n1,int n2){
        if(root==NULL){
            return NULL;
        }

        if(root->val==n1 || root->val==n2){
            return root;
        }

        TreeNode*left=helper(root->left,n1,n2);
        TreeNode*right=helper(root->right,n1,n2);
        if(left==NULL){
            return right;
        }
        if(right==NULL){
            return left;
        }
        return root;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return helper(root,p->val,q->val);
    }
};