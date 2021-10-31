#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node*right;
    node*left;
    node(int val){
        data=val;
        right=NULL;
        left=NULL;
    }
};

bool isSame(node*root1,node*root2){
    if(root1==NULL || root2==NULL){
        return root1==root2;
    }
    return ((root1->data==root2->data) && isSame(root1->left,root2->left) && isSame(root1->right,root2->right));
}

int main(){
    node*root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);

    node*root1=new node(1);
    root1->left=new node(2);
    root1->right=new node(3);
    root1->left->left=new node(4);
    root1->left->right=new node(5);
    root1->right->left=new node(6);
    root1->right->right=new node(7);

    node*root2=new node(1);
    root2->left=new node(2);
    root2->right=new node(3);
    root2->left->left=new node(4);
    root2->left->right=new node(5);
    root2->right->left=new node(6);
    root2->right->right=new node(70);

    cout<<"Is Same : "<<isSame(root,root1)<<endl;
    cout<<"Is Same : "<<isSame(root,root2)<<endl;
}