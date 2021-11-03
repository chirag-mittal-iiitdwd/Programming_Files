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
    bool getPath(vector<int>&arr,int target,node*root){
        if(root==NULL){
            return false;
        }
        arr.push_back(root->data);
        if(root->data==target){
            return true;
        }
        if((getPath(arr,target,root->left))||(getPath(arr,target,root->right))){
            return true;
        }
        arr.pop_back();
        return false;
    }
    public:
    vector<int>pathToTheNode(node*root,int target){
        vector<int>arr;
        getPath(arr,target,root);
        return arr;
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
    int target;
    cin>>target;
    vector<int>path=ob.pathToTheNode(root,target);
    for(auto it:path){
        cout<<it<<" ";
    }
    cout<<endl;
}