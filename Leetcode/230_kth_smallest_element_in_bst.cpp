#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
    void helper(TreeNode*root,int k,int&cnt,int&ans){
        if(root==NULL){
            return;
        }
        helper(root->left,k,cnt,ans);
        cnt++;
        if(cnt==k){
            ans=root->val;
            return;
        }
        helper(root->right,k,cnt,ans);
    }
public:
    int kthSmallest(TreeNode *root, int k){
        int cnt=0,ans=-1;
        helper(root,k,cnt,ans);
        return ans;
    }
};