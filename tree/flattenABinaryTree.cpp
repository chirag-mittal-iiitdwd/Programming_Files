// flatteing the tree into linked without creating another linkedlist
// After flatenning left of each node should become NULL
// right should contain next node in preorder sequence
/*
        1              1
       / \              \
      2   3 ------>      2
         /                \
        4                  3
                            \
                             4 
-------> Algorithm
1. Recursively , flattern the left and right subtrees
      1                  1
     / \                / \
    2   3    ------>   2   3
       / \                  \
      4   5                  4
                              \
                               5   
2. Store the left tail and right tail 
3. Store right subtree in 'temp' and make left subtree as right subtree  
            (tree)           (temp)
               1                3
                \                \
                 2                4
                                   \
                                    5  
4. Join right subtree with left tail                         
5. Return right tail
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

void flattern(node* root){    
   if(root==NULL || (root->left==NULL && root->right==NULL)){
      return;
   }
   if(root->left){
      flattern(root->left);
      // Swapping left to right and left to NULL
      node* temp=root->right;
      root->right=root->left;
      root->left=NULL;

      // Now we have to calculate the tail of root's new right to that we can append the temp
      node* t =root->right;
      while(t->right!=NULL){
         t=t->right;
      }
      t->right=temp;
   }

   // Now if there is any branching in right subtree
   flattern(root->right);
}

void preOrderPrint(node* root){
   if(root==NULL){
      return;
   }
   
   preOrderPrint(root->left);
   cout<<root->data<<" ";
   preOrderPrint(root->right);
}

int main(){
   node* root=new node(4);
   root->left=new node(9);
   root->left->left =new node(1);
   root->left->right=new node(3);
   root->right=new node(5);
   root->right->right=new node(6);
   preOrderPrint(root);cout<<endl;
   flattern(root);
   preOrderPrint(root);
}