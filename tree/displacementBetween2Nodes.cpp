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

/*
-----> Algorithm
1. Find the LCA(Lowest common ancestor)
2. Find distance of n1(d1) and n2(d2) from LCA
3. return (d1+d2)
*/

node* LCA(node* root,int n1,int n2){
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1 || root->data==n2){
        return root;
    }
    node* leftLCA=LCA(root->left,n1,n2);
    node* rightLCA=LCA(root->right,n1,n2);

    // Checking if we got actual LCA's
    if(leftLCA && rightLCA){
        return root;
    }
    // Checking if we didn't got the LCA
    if(!leftLCA && !rightLCA){
        return NULL;
    }
    // 
    if(leftLCA){
        return LCA(root->left,n1,n2);
    }
    return LCA(root->right,n1,n2);
}

int findDist(node* root,int k,int dist){
    if(root==NULL){
        return -1;
    }
    if(root->data==k){
        return dist;
    }
    int left=findDist(root->left,k,dist+1);
    if(left!=-1){
        return left;
    }
    return findDist(root->right,k,dist+1);
}

int distBWNodes(node* root,int n1,int n2){
    node* lca=LCA(root,n1,n2);
    int d1=findDist(lca,n1,0);
    int d2=findDist(lca,n2,0);
    return d1+d2;
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
    root->right=new node(3);
    root->left->left=new node(4);
    root->right->right=new node(5);
    cout<<distBWNodes(root,4,5);
}