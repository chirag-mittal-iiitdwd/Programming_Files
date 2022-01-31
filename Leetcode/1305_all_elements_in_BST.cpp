#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode*right;
    TreeNode*left;
};

class Solution {
    void preorder(TreeNode*root,vector<int>&tree){
        if(root==NULL){
            return;
        }
        preorder(root->left,tree);
        tree.push_back(root->val);
        preorder(root->right,tree);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>tree1,tree2;
        preorder(root1,tree1);
        preorder(root2,tree2);

        vector<int>ans;
        int n=tree1.size(),m=tree2.size(),i=0,j=0;

        while(i<n && j<m){
            if(tree1[i]<tree2[j]){
                ans.push_back(tree1[i]);
                i++;
            }
            else{
                ans.push_back(tree2[j]);
                j++;
            }
        }

        while(j<m){
            ans.push_back(tree2[j]);
            j++;
        }

        while(i<n){
            ans.push_back(tree1[i]);
            i++;
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
    }
};