#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int lh=0,rh=0;
        TreeNode*lRoot=root;
        TreeNode*rRoot=root;

        while(lRoot!=NULL){
            lRoot=lRoot->left;
            lh++;
        }

        while(rRoot!=NULL){
            rRoot=rRoot->left;
            lh++;
        }

        if(lh==rh){
            return pow(2,lh)-1;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};