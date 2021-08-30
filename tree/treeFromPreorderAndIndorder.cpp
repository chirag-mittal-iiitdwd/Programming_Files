#include<iostream>
using namespace std;
/*

------> Algorithm
1. Pick element from preorder and create a node
2. Increment preorder index
3. Search for picked element's pos in inorder
4. Call to build left subtree from inorder's 0 to pos-1
5. Call to build right subtree from inorder's pos+1 to n
6. Return the node 

*/
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

// Start and end represent the starting and ending positions of the indorder sequence
int search(int inorder[],int start,int end,int curr){
    for(int i=start;i<=end;i++){
        if(inorder[i]==curr){
            return i;
        }
    }
    return -1;
}

node* builtTree(int preorder[],int inorder[],int start,int end){
    // Since we have recursion and the value will gwt destroyed once another fuction is called so to prevent that we use static variable because it never dies
    static int idx=0;
    if(start>end){
        return NULL;
    }
    int curr=preorder[idx];
    idx++;
    node* node1=new node(curr);
    if(start==end){
        return node1;
    }
    int pos=search(inorder,start,end,curr);
    node1->left=builtTree(preorder,inorder,start,pos-1);
    node1->right=builtTree(preorder,inorder,pos+1,end);

    return node1;
}

void inoderPrint(node* root){
    if(root==NULL){
        return;
    }
    inoderPrint(root->left);
    cout<<root->data<<" ";
    inoderPrint(root->right);
}

int main(){
    int preorder[]={1,2,4,3,5};
    int inorder[]={4,2,1,5,3};
    node* root=builtTree(preorder,inorder,0,4);
    inoderPrint(root);
    return 0;
}