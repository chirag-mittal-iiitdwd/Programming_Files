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
    int search(vector<int>&inorder,int val,int start,int end){
        for(int i=start;i<=end;i++){
            if(inorder[i]==val){
                return i;
            }
        }
        return -1;
    }
    TreeNode*helper(vector<int>&inorder,vector<int>&preorder,int&preIdx,int start,int end){
        if(start>end){
            return NULL;
        }
        TreeNode*root=new TreeNode(preorder[preIdx++]);
        if(start==end){
            return root;
        }
        int pos=search(inorder,root->val,start,end);
        root->left=helper(inorder,preorder,preIdx,start,pos-1);
        root->right=helper(inorder,preorder,preIdx,pos+1,end);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int preIdx=0,n=preorder.size();
        vector<int>inorder(preorder.begin(),preorder.end());
        sort(inorder.begin(),inorder.end());
        return helper(inorder,preorder,preIdx,0,n-1);
    }
};


class Solution {
public:
int idx=0;
    TreeNode* bstFromPreorder(vector<int>& preorder,int parent_val=INT_MAX) {
        if(idx==preorder.size() || preorder[idx]>parent_val){
            return NULL;
        }
        int current_val=preorder[idx];
        TreeNode*root=new TreeNode(preorder[idx++]);
        root->left=bstFromPreorder(preorder,current_val);
        root->right=bstFromPreorder(preorder,parent_val);
        return root;
    }
};