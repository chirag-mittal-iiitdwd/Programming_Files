/*
Lecture number 27.14
            1             Given node = 5
      1--> / \ <--2           K = 3
          5   2           Ans = {8,9,3,4}
    1--> /   / \ <--3 
        6   3   4
    2--> \   ^<--3
          7
     3-->/ \ <--3
        8   9

1.  First case : Going through subtree 
    and decrease the K value whenever at another node
2.  Find the distance of all ancesstors from target node and name it dth node
    Than Find (K-d)th node in other subtree

*/
// Reckeck
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

// FirstCase
void printSubtreeNodes(node* root,int k){
    if(root==NULL || k<0){
        return;
    }
    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    printSubtreeNodes(root->left,k-1);
    printSubtreeNodes(root->right,k-1);
}
// Case 2
// The return represents the distance from current node to ancestors
int printNodesAtK(node* root,node* target,int k){
    if(root==NULL){
        // havn't got the target node
        return -1;
    }
    if(root==target){
        printSubtreeNodes(root,k);
        return 0;
    }

    // not doing k-1 because we haven't found our node
    int dl=printNodesAtK(root->left,target,k);
    if(dl!=-1){
        if(dl+1==k){
            cout<<root->data<<" ";
        }
        else{
            printSubtreeNodes(root->right,k-dl-2);
        }
        return 1+dl;
    }
    int dr=printNodesAtK(root->right,target,k);
    if(dr!=-1){
        if(dr+1==k){
            // The current node is at kth distance
            cout<<root->data<<" ";
        }
        else{
            printSubtreeNodes(root->left,k-dr-2);
        }
        return 1+dr;
    }

    return -1;
}

int main(){
   node* root=new node(1);
   root->left=new node(2);
   root->left->left =new node(4);
   root->right=new node(3);
   printNodesAtK(root,root->left,1);
}