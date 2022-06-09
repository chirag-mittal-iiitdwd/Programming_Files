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
    bool isMatch(TreeNode*root1,TreeNode*root2){
        if(root1==NULL && root2==NULL){
            return true;
        }
        if(root1!=NULL && root2!=NULL && root1->val!=root2->val){
            return false;
        }
        if((root1!=NULL && root2==NULL)||(root1==NULL && root2!=NULL)){
            return false;
        }

        return isMatch(root1->left,root2->left)&isMatch(root1->right,root2->right);
    }
public:
bool ans=false;
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL){
            ans|=false;
        }
        if(root!=NULL && root->val==subRoot->val && isMatch(root,subRoot)){
            return true;
        }
        if(root->left!=NULL && isSubtree(root->left,subRoot)){
            return true;
        }
        if(root->right!=NULL && isSubtree(root->right,subRoot)){
            return true;
        }
        return ans;
    }
};