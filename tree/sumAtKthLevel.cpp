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

/*

         1
       /   \
      2     3
     / \   / \
    4   5 6   7

*/

int sumAtk(node* root,int k){
    if(root==NULL){
        return -1;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    int level=0;
    int sum=0;
    while(!q.empty()){
        node* node1=q.front();
        q.pop();
        if(node1 != NULL){
            if(level == k){
                sum+=node1->data;
            }
            if(node1 -> left){
                q.push(node1 -> left);
            }
            if(node1 -> right){
                q.push(node1 -> right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
            level++;
        }
    }

    return sum;
}

int main(){
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    int k=2;
    cout<<sumAtk(root,k)<<endl;
}