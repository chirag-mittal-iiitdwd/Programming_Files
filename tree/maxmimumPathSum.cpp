/*
        1
       / \
     -12  3
     /   / \
    4   5  -6

    Here the maximum sum is 1+3+5

-----> Strategy

For each node, compute:
1. Node val
2. Max path through left child + node val
3. Max path through right child + node val
4. Max Path through left child + Max path through right child + node val

Than comparing the path sum with a global variable
than reporting the maximum value
*/

#include"bits/stdc++.h"
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

int maxPathSumUtil(node* root,int &ans){
    if(root==NULL){
        return 0;
    }
    int left=maxPathSumUtil(root->left,ans);
    int right=maxPathSumUtil(root->right,ans);

    int nodeMax=max(max(root->data,root->data+left+right),max(root->data+left,root->data+right));
    ans=max(ans,nodeMax);

    // Now we have to return the maxVal form root
    // Now we wont include root->data+left+right in the value because that would make it complete path sum
    int singlePathSum=max(root->data,max(root->data+left,root->data+right));

    return singlePathSum;
}

int maxPathSum(node* root){
    int ans=INT_MIN;
    // This maxPathSumUtil funcion will be a recursive 
    // Will calcuate all the 4 values and return the maximun of them
    maxPathSumUtil(root,ans);
    return ans;
}

int main(){
    /*
                1
               / \
              2   3
             /     \
            4       5
    */
   node* root=new node(1);
   root->left=new node(2);
   root->left->left=new node(4);
   root->right=new node(3);
   root->right->right=new node(5);

   cout<<maxPathSum(root);
}