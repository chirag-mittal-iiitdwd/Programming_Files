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
    int findMaxIDX(vector<int>&nums,int i,int j){
        int maxi=INT_MIN;
        for(int idx=i;idx<=j;idx++){
            maxi=max(maxi,nums[idx]);
        }
        
        for(int idx=i;idx<=j;idx++){
            if(maxi==nums[idx]){
                return idx;
            }
        }
        return -1;
    }
    TreeNode*createTree(vector<int>&nums,int i,int j){
        if(i>j){
            return NULL;
        }
        int maxIdx=findMaxIDX(nums,i,j);
        TreeNode*root=new TreeNode(nums[maxIdx]);
        root->left=createTree(nums,i,maxIdx-1);
        root->right=createTree(nums,maxIdx+1,j);
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return createTree(nums,0,nums.size()-1);
    }
};


class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        stack<TreeNode*>st;

        for(auto&it:nums){
            TreeNode*cur=new TreeNode(it);
            while(!st.empty() && st.top()->val<cur->val){
                cur->left=st.top();
                st.pop();
            }

            if(!st.empty()){
                st.top()->right=cur;
            }
            st.push(cur);
        }

        while(st.size()>1){
            st.pop();
        }
        return st.top();
    }
};