#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int data){
        val=data;
        left=right=NULL;
    }
};

class Solution {
    TreeNode*helper(vector<int>&nums,int start,int end){
        if(start>end){
            return NULL;
        }
        int mid=(end-((end-start)/2));
        TreeNode*root=new TreeNode(nums[mid]);
        root->left=helper(nums,start,mid-1);
        root->right=helper(nums,mid+1,end);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        return helper(nums,0,n-1);
    }
};
