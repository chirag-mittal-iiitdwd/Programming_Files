#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node*left;
    node*right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

// Try using morris traversal
// class Solution{
//     public:
//     bool BSTorNOT(node*root){
//         unordered_map<int,int>mp;
//         int maxi=INT_MIN;
//         node*cur=root;
//         while(cur!=NULL){
//             if(cur->left==NULL){
//                 maxi=max(maxi,cur->data);
//                 mp[cur->data]++;
//                 if(maxi!=cur->data){
//                     return false;
//                 }
//                 cur=cur->right;
//             }
//             else{
//                 node*prev=cur->left;
//                 while(prev->right && prev->right!=cur){
//                     prev=prev->right;
//                 }
//                 if(prev->right==NULL){
//                     prev->right=cur;
//                     cur=cur->left;
//                 }
//                 else{
//                     prev->right=NULL;
//                     maxi=max(maxi,cur->data);
//                     if(maxi!=cur->data){
//                         return false;
//                     }
//                     cur=cur->right;
//                 }
//             }
//         }
//         return true;
//     }
// };

class Solution{
    bool isBST1(node*root,int mini,int maxi){
        if(root==NULL){
            return true;
        }
        if(root->data>=maxi || root->data<=mini){
            return false;
        }
        return isBST1(root->left,mini,root->data)&&isBST1(root->right,root->data,maxi);
    }
    public:
    bool isBST(node*root){
        return isBST1(root,INT_MIN,INT_MAX);
    }
};