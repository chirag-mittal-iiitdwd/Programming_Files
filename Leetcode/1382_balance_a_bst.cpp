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

// Time -> O(N) + O(N)
// Space -> O(N)
class Solution {
    void collectBst(TreeNode*root,vector<int>&ans){
        if(root==NULL){
            return;
        }
        collectBst(root->left,ans);
        ans.push_back(root->val);
        collectBst(root->right,ans);
    }
    TreeNode*makeBalancedBst(vector<int>&inorder,int start,int end){
        if(start>end){
            return NULL;
        }
        int idx=(start+end)/2;
        TreeNode*root=new TreeNode(inorder[idx]);
        if(start==end){
            return root;
        }
        root->left=makeBalancedBst(inorder,start,idx-1);
        root->right=makeBalancedBst(inorder,idx+1,end);
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>ans;
        collectBst(root,ans);
        return makeBalancedBst(ans,0,ans.size()-1);
    }
};

