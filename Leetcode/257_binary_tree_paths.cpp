#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode*left;
    TreeNode*right;
};

class Solution {
    bool isLeaf(TreeNode*root){
        if(root!=NULL && root->left==NULL && root->right==NULL){
            return true;
        }
        return false;
    }
    void helper(TreeNode*root,string cur,vector<string>&ans){
        // if(root==NULL){
        //     return;
        // }
        if(isLeaf(root)){
            ans.push_back(cur);
            return;
        }
        if(root->left){
            helper(root->left,cur+"->"+to_string(root->left->val),ans);
        }
        if(root->right){
            helper(root->right,cur+"->"+to_string(root->right->val),ans);
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string cur;
        if(root==NULL){
            return ans;
        }
        else if(isLeaf(root)){
            cur+=to_string(root->val);
            ans.push_back(cur);
            return ans;
        }
        else{
            cur+=to_string(root->val);
            helper(root,cur,ans);
            return ans;
        }
    }
};

int main(){

}