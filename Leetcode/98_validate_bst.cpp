#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool helper(TreeNode*root,long lowerLim,long upperLim){
        if(root==NULL){
            return true;
        }
        if(root->val>=upperLim || root->val<=lowerLim){
            return false;
        }
        return helper(root->left,lowerLim,root->val)&&helper(root->right,root->val,upperLim);
    }
public:
    bool isValidBST(TreeNode* root) {
        return helper(root,LONG_MIN,LONG_MAX);
    }
};