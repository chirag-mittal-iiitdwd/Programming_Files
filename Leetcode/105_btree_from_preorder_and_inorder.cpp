#include <bits/stdc++.h>
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

class Solution{
    int search(vector<int>&inorder,int val,int start,int end){
        for(int i=start;i<=end;i++){
            if(inorder[i]==val){
                return i;
            }
        }
        return -1;
    }
    TreeNode*helper(vector<int>&preorder,vector<int>&inorder,int start,int end,int&preIdx){
        if(start>end){
            return NULL;
        }
        TreeNode*root=new TreeNode(preorder[preIdx++]);
        if(start==end){
            return root;
        }
        int pos=search(inorder,root->val,start,end);
        root->left=helper(preorder,inorder,start,pos-1,preIdx);
        root->right=helper(preorder,inorder,pos+1,end,preIdx);
        return root;
    }
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder){
        int preIdx=0;
        return helper(preorder,inorder,0,inorder.size()-1,preIdx);
    }
};