#include<bits/stdc++.h>
using namespace std;

class Solution {
    int ans=0;
    void helper(int minVal,int maxVal,TreeNode*root){
        if(minVal!=INT_MAX){
            ans=max(ans,abs(minVal-root->val));
        }
        if(maxVal!=INT_MIN){
            ans=max(ans,abs(maxVal-root->val));
        }
        maxVal=max(maxVal,root->val);
        minVal=min(minVal,root->val);
        if(root->left){
            helper(minVal,maxVal,root->left);
        }
        if(root->right){
            helper(minVal,maxVal,root->right);
        }
        return;
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        helper(INT_MAX,INT_MIN,root);
        return ans;
    }
};