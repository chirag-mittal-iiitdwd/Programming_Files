#include<bits/stdc++.h>
using namespace std;
#define int long long int

class TreeNode{
    public:
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int data){
        val=data;
        left=NULL;
        right=NULL;
    }
};

class Solution {
    int binaryToNumber(string bin){
        int n=0;
        int idx=0;
        int len=bin.length();
        for(int i=len-1;i>=0;i--){
            int cur=bin[i]-'0';
            n|=(cur<<idx);
            idx++;
        }
        return n;
    }
    int helper(TreeNode*&root,string bin){
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL && root->right==NULL){
            bin+=to_string(root->val);
            int x=binaryToNumber(bin);
            return x;
        }
        bin+=to_string(root->val);
        return helper(root->left,bin)+helper(root->right,bin);
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        string bin{""};
        return helper(root,bin);
    }
};

class Solution{
    int helper(TreeNode*root,int val){
        if(!root){
            return 0;
        }
        val=((val<<1)|root->val);
        if(!root->left && !root->right){
            return val;
        }
        return helper(root->left,val)+helper(root->right,val);
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        return helper(root,0);
    }
};

int32_t main(){

    return 0;
}