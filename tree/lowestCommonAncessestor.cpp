// We will find the path for the first node and store it
// Than we will find the path for the second node and store it
// Analysing to find the ancesstor which came at the last

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

bool getPath(node* root,int key,vector<int> &path){
    if(root==NULL){
        return false;
    }
    path.push_back(root->data);
    if(root->data==key){
        return true;
    }
    if(getPath(root->left,key,path) || getPath(root->right,key,path)){
        return true;
    }
    path.pop_back();
    return false;
}

// O(n)
int LCA(node* root,int n1,int n2){
    vector<int> path1,path2; // For storing paths
    // getPath returns a boolean value to check if the path exists or not
    if(!getPath(root,n1,path1) || !getPath(root,n2,path2)){
        return -1;
    }

    int pathChange;
    for(pathChange=0;pathChange<path1.size() && path2.size();pathChange++){
        if(path1[pathChange]!=path2[pathChange]){
            break;
        }
    }

    return path1[pathChange-1];
}

// O(n)
// node* LCA2(node* root,int n1,int n2){
//     if(root==NULL){
//         return NULL;
//     }
//     if(root->data==n1 || root->data==n2){
//         return root;
//     }
//     node* leftLCA=LCA2(root->left,n2,n1);
//     node* rightLCA=LCA2(root->right,n2,n1);
//     if(leftLCA && rightLCA){
//         return root;
//     }

//     if(leftLCA){
//         return leftLCA;
//     }
//     return rightLCA;
// }

node* LCA2(node* root,int n1,int n2){
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1 || root->data==n2){
        return root;
    }
    node* leftLCA=LCA2(root->left,n1,n2);
    node* rightLCA=LCA2(root->right,n1,n2);

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
        return LCA2(root->left,n1,n2);
    }
    return LCA2(root->right,n1,n2);
}

int main(){
    /*
                1
               / \
              2   3
             /   / \
            4   5   6 
               /
              7
    */

   node* root=new node(1);
   root->left=new node(2);
   root->right=new node(3);
   root->left->left=new node(4);
   root->right->left=new node(5);
   root->right->left->left=new node(7);
   root->right->right=new node(6);

   int n1=7;
   int n2=6;
   int lca=LCA(root,n1,n2);
   cout<<lca<<endl;
   node*temp=LCA2(root,n1,n2);
   cout<<temp->data<<endl;
}