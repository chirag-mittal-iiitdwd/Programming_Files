#include<iostream>
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
-----> Approach - 1
1. find out max of leftSubtree (maxL)
2. find out min of rightSubtree (minR)
3. if(minR>maxL) than true

-----> Approach - 2
1. two variables min allowed and max allowed
2. min allowed < node && max allowed > node
                node(min,max)
                /           \
         left(min,node)   right(node,right)    
*/

bool isBST(node* root,node* min=NULL,node* max=NULL){
    if(root==NULL){
        return true;
    }
    if(min && root->data<=min->data){
        return false;
    }
    if(max && root->data>=max->data){
        return false;
    }
    bool leftValid=isBST(root->left,min,root);
    bool rightValid=isBST(root->right,root,max);

    return (leftValid && rightValid);
}

int main(){
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    /*
            1
           / \
          2   3
    */
    cout<<isBST(root)<<endl;

    node* root2=new node(5);
    root2->left=new node(2);
    root2->right=new node(7);
    /*
            5
           / \
          2   7
    */
    cout<<isBST(root2)<<endl;
}