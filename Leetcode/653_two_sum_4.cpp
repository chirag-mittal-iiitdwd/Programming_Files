#include<bits/stdc++.h>
using namespace std;

// class Solution {
//     bool search(TreeNode*root,int key){
//         if(root==NULL){
//             return false;
//         }
//         if(root->val==key){
//             return true;
//         }
//         if(root->val<key){
//             return search(root->right,key);
//         }
//         return search(root->left,key);
//     }
//     bool findTarget(TreeNode*root,TreeNode*temp,int k){
//         if(root==NULL){
//             return false;
//         }
//         cout<<k-root->val<<endl;
//         if(search(temp,k-root->val)){
//             return true;
//         }
//         return (findTarget(root->left,temp,k)||findTarget(root->right,temp,k));
//     }
// public:
//     bool findTarget(TreeNode* root, int k) {
//         if(root==NULL || (root->left==NULL && root->right==NULL)){
//             return false;
//         }
//         return findTarget(root,root,k);
//     }
// };

class Solution {
    unordered_map<int,int>mp;
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL){
            return false;
        }
        if(mp[k-root->val]!=0){
            return true;
        }
        mp[root->val]++;
        return findTarget(root->left,k)||findTarget(root->right,k);
    }
};