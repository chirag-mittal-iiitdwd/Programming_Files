#include<bits/stdc++.h>
using namespace std;

/*
    At any point we can say that till that point the height is 1+max(left subtree,right subtree)

    We can solve this by level order traversal and recursion
    in recursion the worst case complexity will be when we have a squed tree
    in level order traversal the worst case complexity will be when we have complete binary tree
*/

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

int heightOrDepthOfbinaryTree(node*root){
    if(root==NULL){
        return 0;
    }
    int lh=heightOrDepthOfbinaryTree(root->left);
    int rh=heightOrDepthOfbinaryTree(root->right);
    return 1+max(lh,rh);
}

int balancedBinaryTreeCheck(node*root){
    if(root==NULL){
        return 0;
    }
    int lh=balancedBinaryTreeCheck(root->left);
    int rh=balancedBinaryTreeCheck(root->right);
    if((lh==-1) || (rh==-1) || (abs(lh-rh)>1)){
        return -1;
    }
    return 1+max(lh,rh);
}

// Time complexity = O(n^2) n=number of nodes ---> Worst case when skues tree
int calcDiameter(node* root){
    if(root==NULL){
        return 0;
    }
    int lHeight=heightOrDepthOfbinaryTree(root->left);
    int rHeight=heightOrDepthOfbinaryTree(root->right);
    int currDiameter=lHeight+rHeight+1;
 
    int lDiameter=calcDiameter(root->left);
    int rDiameter=calcDiameter(root->right);
 
    return max(currDiameter,max(lDiameter,rDiameter));
}

class calcDiameterOpti{
    int height(node*root,int& diameter){
        if(root==NULL){
            return 0;
        }
        int lh=height(root->left,diameter);
        int rh=height(root->right,diameter);
        diameter=max(diameter,lh+rh+1);
        return 1+max(lh,rh);
    }
    public:
    int diameterOpti(node*root){
        int diameter=0;
        height(root,diameter);
        return diameter;
    }
};

class maximumPathSum{
    int maxPath(node*root,int&maxi){
        if(root==NULL){
            return 0;
        }
        int left=max(0,maxPath(root->left,maxi));
        int right=max(0,maxPath(root->right,maxi));
        maxi=max(maxi,left+right+root->data);
        return max(left,right)+root->data;
    }
    public:
    int maxPathSum(node*root){
        int maxi=INT_MIN;
        maxPath(root,maxi);
        return maxi;
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

    cout<<heightOrDepthOfbinaryTree(root)<<endl;
    cout<<balancedBinaryTreeCheck(root)<<endl;
    cout<<"Diameter : "<<calcDiameter(root)<<endl;
    calcDiameterOpti obj;
    cout<<"diameter opti : "<<obj.diameterOpti(root)<<endl;
    maximumPathSum ob;
    cout<<"maximum path sum : "<<ob.maxPathSum(root)<<endl;
}