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
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        queue<TreeNode*>q;
        q.push(root);
        vector<int>ans;

        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                if(i==size-1){
                    ans.push_back(q.front()->val);
                }
                if(q.front()->left!=NULL){
                    q.push(q.front()->left);
                }
                if(q.front()->right!=NULL){
                    q.push(q.front()->right);
                }
                q.pop();
            }
        }

        return ans;
    }
};

class Solution{
    void helper(TreeNode*root,vector<int>&ans,int level){
        if(root==NULL){
            return;
        }
        if(ans.size()==level){
            ans.push_back(root->val);
        }
        helper(root->right,ans,level+1);
        helper(root->right,ans,level+1);
    }
    public:
    vector<int>rightSideView(TreeNode*root){
        vector<int>ans;
        helper(root,ans,0);
        return ans;
    }
};