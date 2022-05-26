#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
    int search(vector<int>&inorder,int start,int end,int val){
        for(int i=start;i<=end;i++){
            if(val==inorder[i]){
                return i;
            }
        }
        return -1;
    }
    TreeNode*helper(vector<int>&inorder,vector<int>&postorder,int start,int end,int&postIdx){
        if(start>end){
            return NULL;
        }
        TreeNode*root=new TreeNode(postorder[postIdx]);
        postIdx--;
        if(start==end){
            return root;
        }
        int pos=search(inorder,start,end,root->val);
        root->right=helper(inorder,postorder,pos+1,end,postIdx);
        root->left=helper(inorder,postorder,start,pos-1,postIdx);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIdx=inorder.size()-1;
        return helper(inorder,postorder,0,inorder.size()-1,postIdx);
    }
};