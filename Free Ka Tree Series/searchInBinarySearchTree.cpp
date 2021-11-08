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

// Time Complity : log2(N)
class Solution{
    // TreeNode* searchBST(TreeNode* root, int val) {
    //      while(root != NULL && root->val != val){
    //         root = val<root->val? root->left:root->right;
    //     }
    //     return root;
    // }
    public:
    node* searchInBST(node*root,int target){
        if(root==NULL){
            return NULL;
        }
        if(root->data==target){
            return root;
        }
        if(root->data<target){
            return searchInBST(root->right,target);
        }
        return searchInBST(root->left,target);
    }
};

int main(){
    node*root=new node(8);
    root->left=new node(5);
    root->right=new node(12);
    root->left->left=new node(4);
    root->right->right=new node(14);
    root->left->right=new node(7);
    root->left->right->left=new node(6);
    root->right->left=new node(10);
    root->right->right->left=new node(13);

    Solution onj;
    cout<<onj.searchInBST(root,13)->data<<endl;
}