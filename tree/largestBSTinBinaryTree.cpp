/*
----> For each node store the following information
1. min in subtree 
2. max in subtree
3. subtree size
4. size of largest BST
5. isBST

Than recursively traverse in a bottom-up manner 
and find out the size of largest BST
*/

#include<iostream>
#include<climits>
using namespace std;

class node{
    public:
    int data;
    node* right;
    node* left;
    node(int val){
        data=val;
        right=NULL;
        left=NULL;
    }
};

class info{
    public:
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};

info largestBSTinBT(node* root){
    if(root==NULL){
        return {0,INT_MIN,INT_MAX,0,true};
    }

    // Cheking if there is a single node
    if(root->left==NULL && root->right==NULL){
        return {1,root->data,root->data,1,true};
    }
    info leftInfo=largestBSTinBT(root->left);
    info rightInfo=largestBSTinBT(root->right);

    info curr;
    curr.size=(1+leftInfo.size+rightInfo.size);
    if(leftInfo.isBST && rightInfo.isBST && leftInfo.max<root->data && rightInfo.min>root->data){
        curr.min=min(leftInfo.min,min(rightInfo.min,root->data));
        curr.max=max(leftInfo.min,max(rightInfo.max,root->data));
        curr.ans=curr.size; 
        curr.isBST=true;
        return curr;
    }
    // If at current node BST is not formed 
    curr.ans=max(leftInfo.ans,rightInfo.ans);
    curr.isBST=false;

    return curr;
}

int main(){
    /* 
            15
           /  \
          20   30
         /
        5  
     */
    node* root=new node(15);
    root->left=new node(20);
    root->left->left=new node(5);
    root->right=new node(30);

    cout<<"Largest BST in BT : "<<largestBSTinBT(root).ans<<endl;
}