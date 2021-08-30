#include<iostream>
using namespace std;

/*

------> Algorithm
1. Start from the end of postorder and Pick element to create a node
2. Decrement postorder index
3. Search for picked element's pos in inorder
4. Call to build right subtree from inorder's pos+1 to n
5. Call to build left subtree from inorder's 0 to pos-1
6. Return the node 

*/
// From postorder and preorder we cannot build one tree
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

int search(int inorder[],int start,int end,int curr){
    for(int i=start;i<=end;i++){
        if(inorder[i]==curr){
            return i;
        }
    }
    return -1;
}

node* builtTree(int postorder[],int inorder[],int start,int end){
    static int idx=end;
    if(start>end){
        return NULL;
    }
    int curr=postorder[idx];
    idx--;
    node* node1=new node(curr);
    if(start==end){
        return node1;
    }
    int pos=search(inorder,start,end,curr);
    node1->right=builtTree(postorder,inorder,pos+1,end);
    node1->left=builtTree(postorder,inorder,start,pos-1);

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
    int postorder[]={4,5,2,6,7,3,1};
    int inorder[]={4,2,5,1,6,3,7};
    node* root=builtTree(postorder,inorder,0,6);
    inoderPrint(root);
}