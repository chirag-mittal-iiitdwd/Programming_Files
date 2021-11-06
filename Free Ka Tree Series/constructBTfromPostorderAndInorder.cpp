#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node*right;
    node*left;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

class Solution{
    node*mainLogic(vector<int>postorder,vector<int>inorder,int inStart,int inEnd,map<int,int>inMap){
        static int postIDX=postorder.size()-1;
        if(inStart>inEnd) return NULL;

        int curr=postorder[postIDX--];
        int rootIDX=inMap[curr];
        node*root=new node(curr);
        if(inStart==inEnd){
            return root;
        }
        
        root->right=mainLogic(postorder,inorder,rootIDX+1,inEnd,inMap);
        root->left=mainLogic(postorder,inorder,inStart,rootIDX-1,inMap);
        return root;
    }
    public:
    node*buildTree(vector<int>postorder,vector<int>inorder){
        map<int,int>inMap;
        for(int i=0;i<inorder.size();i++){
            inMap[inorder[i]]=i;
        }
        return mainLogic(postorder,inorder,0,inorder.size()-1,inMap);
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
    vector<int>postorder={40,50,20,60,30,10};
    Solution ob;
    node*root=ob.buildTree(postorder,inorder);
    inorderPrint(root);cout<<endl;
}