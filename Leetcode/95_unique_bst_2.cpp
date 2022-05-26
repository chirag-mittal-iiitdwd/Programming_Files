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
    vector<TreeNode*>helper(int start,int end){
        vector<TreeNode*>ans;
        if(start>end){
            ans.push_back(NULL);
            return ans;
        }
        if(start==end){
            ans.push_back(new TreeNode(start));
            return ans;
        }

        for(int i=start;i<=end;i++){
            vector<TreeNode*>leftPossibleTrees=helper(start,i-1);
            vector<TreeNode*>rightPossibleTrees=helper(i+1,end);
            
            for(auto&leftRoot:leftPossibleTrees){
                for(auto&rightRoot:rightPossibleTrees){
                    TreeNode*root=new TreeNode(i);
                    root->left=leftRoot;
                    root->right=rightRoot;
                    ans.push_back(root);
                }
            }
        }

        return ans;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return helper(1,n);
    }
};