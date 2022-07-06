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
    int sumTree(TreeNode*root,int&cnt){
        if(root==NULL){
            return 0;
        }
        cnt++;
        int leftVal=sumTree(root->left,cnt);
        int rightVal=sumTree(root->right,cnt);
        return (root->val+leftVal+rightVal);
    }
    void helper(TreeNode*&root,int&ans){
        if(root==NULL){
            return; 
        }
        int cnt=0;
        int avg=sumTree(root,cnt)/cnt;
        if(avg==root->val){
            ans++;
        }
        helper(root->left,ans);
        helper(root->right,ans);
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        helper(root,ans);
        return ans;
    }
};

class Solution {
    int cnt=0;
    pair<int,int>helper(TreeNode*root){
        if(root==NULL){
            return {0,0};
        }

        pair<int,int>leftVal=helper(root->left);
        pair<int,int>rightVal=helper(root->right);
        int sum=root->val+leftVal.first+rightVal.first;
        int n=1+leftVal.second+rightVal.second;
        if((sum/n)==root->val){
            cnt++;
        }
        return {sum,n};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        helper(root);
        return cnt;
    }
};