#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node*right;
    node*left;
    node(int val){
        data=val;
        right=NULL;
        left=NULL;
    }
};

class bruteForce{
    bool getPath(node*root,vector<int>&arr,int target){
        if(root==NULL){
            return false;
        }
        arr.push_back(root->data);
        if(root->data==target){
            return true;
        }
        if(getPath(root->left,arr,target)||getPath(root->right,arr,target)){
            return true;
        }
        arr.pop_back();
        return false;
    }
    public:
    int lca(node*root,int val1,int val2){
        vector<int>arr1;
        vector<int>arr2;
        getPath(root,arr1,val1);
        getPath(root,arr2,val2);
        if(arr1.size()==0 || arr2.size()==0){
            return INT_MAX;
        }
        int cnt=0;
        while(arr1[cnt]==arr2[cnt]){
            cnt++;
        }
        node*n;
        n->data=arr1[cnt-1];
        return arr2[cnt-1];
    }
};

class Solution{
    public:
    node*lca(node*root,int val1,int val2){
        if(root==NULL || root->data==val1 || root->data==val2){
            return root;
        }
        node*left=lca(root->left,val1,val2);
        node*right=lca(root->right,val1,val2);
        if(left==NULL){
            return right;
        }
        else if(right==NULL){
            return left;
        }
        else{
            return root;
        }
    }
};

/*
             1
           /  \
          2    3
         / \  / \
        4   5 6  7
*/

int main(){
    node*root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);

    Solution ob;
    cout<<ob.lca(root,6,7)->data<<endl;
}