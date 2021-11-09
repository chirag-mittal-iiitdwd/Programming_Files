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

// class Solution{
//     node*BSTfromPreorder(vector<int>preorder,int&start){
//         if(start==preorder.size()){
//             return NULL;
//         }
//         node*root=new node(preorder[start]);
//         start++;
//         if(start<preorder.size() && preorder[start]<=root->data){
//             root->left=BSTfromPreorder(preorder,start);
//         }
//         if(start<preorder.size() && preorder[start]>root->data){
//             root->right=BSTfromPreorder(preorder,start);
//         }
//         return root;
//     }
//     public:
//     node*constructBSTfromPreorder(vector<int>preodrer){
//         int start=0;
//         return BSTfromPreorder(preodrer,start);
//     }
// };

class Solution{
    node*BSTfromPreorder(vector<int>preorder,int&start,int bound){
        if(start==preorder.size() || preorder[start]>bound){
            return NULL;
        }
        node*root=new node(preorder[start++]);
        root->left=BSTfromPreorder(preorder,start,root->data);
        root->right=BSTfromPreorder(preorder,start,bound);
        return root;
    }
    public:
    node*constructBSTfromPreorder(vector<int>preodrer){
        int start=0;
        return BSTfromPreorder(preodrer,start,INT_MAX);
    }
};

void inorder(node*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    vector<int>p={8,5,1,7,10,12};
    Solution obj;
    node*n=obj.constructBSTfromPreorder(p);
    inorder(n);
}