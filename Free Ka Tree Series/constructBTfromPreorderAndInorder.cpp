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

/*
    Time Complexity : O(N)
    Space Complexity : O(N)
*/
class Solution{
    node* mainLogic(vector<int>preorder,vector<int>inorder,int inStart,int inEnd,map<int,int>&inMap){
        static int preIndex=0;
        if(inStart>inEnd){
            return NULL;
        }

        // Creating the root node with preorder's first element
        int curr=preorder[preIndex++];
        node* root=new node(curr);
        if(inStart==inEnd){
            return root;
        }

        int inIndex=inMap[curr];
        root->left=mainLogic(preorder,inorder,inStart,inIndex-1,inMap);
        root->right=mainLogic(preorder,inorder,inIndex+1,inEnd,inMap);
        return root;
    }
    public:
    node* buildTree(vector<int>preorder,vector<int>inorder){
        map<int,int>inMap;
        // Storing the poistion of nodes in inorder
        for(int i=0;i<inorder.size();i++){
            inMap[inorder[i]]=i;
        }
        return mainLogic(preorder,inorder,0,inorder.size()-1,inMap);
    }
};

void inorderPrint(node*root){
    if(root==NULL){
        return;
    }
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

int main(){
    vector<int>inorder={40,20,50,10,60,30};
    vector<int>preorder={10,20,40,50,30,60};
    Solution obj;
    node*root=obj.buildTree(preorder,inorder);
    inorderPrint(root);
}