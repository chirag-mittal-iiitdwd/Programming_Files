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
    bool isLeaf(TreeNode*root){
        if(root->left==NULL && root->right==NULL){
            return true;
        }
        return false;
    }
    void helper(TreeNode*root,int targetSum,vector<vector<int>>&ans,int localSum,vector<int>localValues){
        if(root==NULL){
            return;
        }
        if(isLeaf(root)){
            if(root->val+localSum==targetSum){
                localValues.push_back(root->val);
                ans.push_back(localValues);
                return;
            }
            return;
        }
        
        localValues.push_back(root->val);
        localSum+=root->val;
        helper(root->left,targetSum,ans,localSum,localValues);
        helper(root->right,targetSum,ans,localSum,localValues);
    }
    public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum){
        vector<int>localValues;
        int localSum=0;
        vector<vector<int>>ans;
        helper(root,targetSum,ans,localSum,localValues);
        return ans;
    }
};