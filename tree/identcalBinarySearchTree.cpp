/*
--------> Algorithm
Given is the root of each tree
1. If both are empty are the same time, return true
2. If both are non-empty
    a. Check that the data at nodes is equal
    b. Check if left subtrees are same
    c. Check if right subtrees are same
3. If(a,b,c) are ture, return true
    else, return false
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

// bool isIdentical(node* root1,node* root2){
//     if(root1==NULL && root2==NULL){
//         return true;
//     }
//     if(root1==NULL && root2!=NULL){
//         return false;
//     }
//     if(root2==NULL && root1!=NULL){
//         return false;
//     }
//     bool a=false;
//     if(root1->data==root2->data){
//         a=true;
//     }
//     if(isIdentical(root1->left,root2->left) && isIdentical(root1->right,root2->right) && a){
//         return true;
//     }
//     return false;
// }

// Second way of writing
bool isIdentical(node* root1,node* root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    else if(root1==NULL || root2==NULL){
        return false;
    }
    else{
        bool cond1=root1->data==root2->data;
        bool cond2=isIdentical(root1->left,root2->left);
        bool cond3=isIdentical(root1->right,root2->right);
        if(cond1 && cond2 && cond3){
            return true;
        }
        return false;
    }
}

int main(){
    /*  Case 1
            1                 1
           / \               / \
          2   3    and      2   3
         / \               / \
        4   5             4   5

        case 2
            1                 1
           / \               / \
          2   3    and      2   3
         / \               / \
        4   5             4   7
    */
    node* root1=new node(1);
    root1->left=new node(2);
    root1->left->left=new node(4);
    root1->left->right=new node(5);
    root1->right=new node(3);

    node* root2=new node(1);
    root2->left=new node(2);
    root2->left->left=new node(4);
    root2->left->right=new node(5);
    root2->right=new node(3);

    node* root3=new node(1);
    root3->left=new node(2);
    root3->left->left=new node(4);
    root3->left->right=new node(7);
    root3->right=new node(3);

    node* root4=new node(1);
    root4->left=new node(2);
    root4->left->left=new node(4);
    root4->left->right=new node(5);

    // 1 and 2 are identical
    // 1 and 3 has one value different
    // 1 and 4 has structural didderence
    cout<<isIdentical(root1,root2)<<endl;
    cout<<isIdentical(root1,root3)<<endl;
    cout<<isIdentical(root1,root4)<<endl;
}