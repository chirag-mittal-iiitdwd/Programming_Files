/*
    Left boundry excluding leaf

    Leaf nodes

    Right boundry in reverse excluding leaf
*/

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

class Solution{
    bool isLeaf(node*root){
        return ((!root->left)&&(!root->right));
    }
    void addLeftBoundry(node*root,vector<int>&res){
        node*cur=root->left;
        while(cur){
            if(!isLeaf(cur)){
                res.push_back(cur->data);
            }
            if(cur->left){
                cur=cur->left;
            }
            else{
                cur=cur->right;
            }
        }
    }

    void addRightBoundry(node*root,vector<int>&res){
        node*cur=root->right;
        vector<int>temp;
        while(cur){
            if(!isLeaf(cur)){
                temp.push_back(cur->data);
            }
            if(cur->right){
                cur=cur->right;
            }
            else{
                cur=cur->left;
            }
        }

        for(int i=temp.size()-1;i>=0;i--){
            res.push_back(temp[i]);
        }
    }

    void addLeaves(node*root,vector<int>&res){
        if(isLeaf(root)){
            res.push_back(root->data);
            return;
        }
        if(root->left){
            addLeaves(root->left,res);
        }
        if(root->right){
            addLeaves(root->right,res);
        }
    }

    public:
    vector<int>printBoundry(node*root){
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        if(!isLeaf(root)){
            ans.push_back(root->data);
        }
        addLeftBoundry(root,ans);
        addLeaves(root,ans);
        addRightBoundry(root,ans);
        return ans;
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

    Solution obj;
    vector<int>ans=obj.printBoundry((root));
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
}