/* 
Inorder of a BST is sorted
2 Elements in a sorted array are swapped

Case 1: 
    Swapped elements are not adjacent to each other
    original = {1,2,3,4,5,6,7,8}
    after swapping = {1,8,3,4,5,6,7,2}
Case 2:
    Swapped elements are adjacent to each other
    original = {1,2,3,4,5,6,7,8}
    after swapping = {1,2,4,3,5,6,7,8}

Maintain 3 pointers - first, last and mid
Case 1:
    first : previous node where 1st number < previous [8]
    Mid : number where 1st number < previous [3]
    Last : 2nd node where number < previous[2] 
    swap firs with last
Case 2:
    first : previous node where 1st number < previous [4]
    Mid : number where 1st number < previous [3]
    Last : NULL ( Since we know both are adjacent)
    swap first and mid
*/

#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int val){
        data=val;
        right=NULL;
        left=NULL;
    }
};

void swapFunction(int &n1,int &n2){
    int temp=n1;
    n1=n2;
    n2=temp;
}

// Traversing the tree in inorder fashion and calcuating the pointers
void calcPointers(node* &root,node* &first,node* &mid,node* &last,node* &prev){
    if(root==NULL){
        return;
    }
    // Like in inorder we first traverse for root->left
    calcPointers(root->left,first,mid,last,prev);
    // Checking if the property is voilated or not
    // If violation is happening than check is it first time or second
    if(prev && root->data<prev->data){
        // if the property would has violated for the first time time than 
        // first pointer will be NULL
        if(!first){
            first=prev;
            mid=root;
        }
        // After that root will point to last node
        else{
            last=root;
        }
    }
    prev=root;
    calcPointers(root->right, first,mid,last,prev);
}

void restoreBST(node* &root){
    node* first=NULL;
    node* mid=NULL;
    node* last=NULL;
    node* prev=NULL;
    calcPointers(root,first,mid,last,prev);
    if(first && last){
        swapFunction(first->data,last->data);
    }
    else if(first && mid){
        swapFunction(first->data,mid->data);
    }
}

void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    /* 
            6
          /  \
         9   3
       / \   \
      1  4   13
    */
    node* root=new node(6);
    root->left=new node(9);
    root->left->left=new node(1);
    root->left->right=new node(4);
    root->right=new node(3);
    root->right->right=new node(13);
    inorder(root);cout<<endl;
    restoreBST(root);
    inorder(root);cout<<endl;
    return 0;
}