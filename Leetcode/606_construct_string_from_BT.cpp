#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string tree2str(TreeNode* root) {
        if(root==NULL){
            return "";
        }
        string ans=to_string(root->val);
        ans+=to_string(root->val);
        if(root->left!=NULL){
            ans+='('+tree2str(root->left)+')';
        }
        else{
            ans+="()";
        }
        if(root->right==NULL){
            ans+='('+tree2str(root->right)+')';
        }
        return ans;
    }
};