#include<bits/stdc++.h>
using namespace std;
#define int long long int

class Solution {
    TreeNode*helper(TreeNode*root,int val){
        if(root==NULL){
            root=new TreeNode(val);
            return root;
        }
        if(root->val>val){
            return helper(root->left,val);
        }
        else{
            return helper(root->right,val);
        }
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        ios_base::sync_with_stdio(false);
        return helper(root,val);
    }
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            root=new TreeNode(val);
            return root;
        }
        if(root->val>val){
            root->left=insertIntoBST(root->left,val);
        }
        else{
            root->right=insertIntoBST(root->right,val);
        }
        return root;
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    return 0;
}