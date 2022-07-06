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
    #define no_cam 0
    #define has_cam 2
    #define no_need 1
    int dfs(TreeNode*root,int&ans){
        if(root==NULL){
            return no_need;
        }
        int left=dfs(root->left,ans);
        int right=dfs(root->right,ans);
        if(left==no_cam || right==no_cam){
            ans++;
            return has_cam;
        }
        else if(left==has_cam || right==has_cam){
            return no_need;
        }
        else{
            return no_cam;
        }
    }
public:
    int minCameraCover(TreeNode* root) {
        int ans=0;
        if(dfs(root,ans)==no_cam){
            ans++;
        }
        return ans;
    }
};