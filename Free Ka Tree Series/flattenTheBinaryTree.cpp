#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node*left;
    node*right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

class recursiveSolution{
    node*prev=NULL;
    public:
    void flatten(node*&root){
        if(root==NULL){
            return ;
        }
        flatten(root->right);
        flatten(root->left);
        root->right=prev;
        root->left=NULL;
        prev=root;
    }
};

class iterativeSolution{
    public:
    void flatten(node*&root){
        if(root==NULL){
            return ;
        }
        stack<node*>st;
        st.push(root);
        while(!st.empty()){
            node*cur=st.top();
            st.pop();
            if(cur->right!=NULL){
                st.push(cur->right);
            }
            if(cur->left!=NULL){
                st.push(cur->left);
            }
            if(!st.empty()){
                cur->right=st.top();
            }
            cur->left=NULL;
        }
    }
};

class iterativeMorrisIntution{
    public:
    void flatten(node*&root){
        node*cur=root;
        while(cur){
            if(cur->left){
                node*prev=cur->left;
                while(prev->right){
                    prev=prev->right;
                }
                prev->right=cur->right;
                cur->right=cur->left;
                cur->left=NULL;
            }

            // We changed cur->left to cur->right that is why we now move to cur->right
            cur=cur->right;
        }
    }
};

void inorder(node*root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    node*root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);

    recursiveSolution obj;
    iterativeSolution obj1;
    iterativeMorrisIntution obj2;
    node*root1=root;
    node*root2=root;
    node*root3=root;
    obj.flatten(root1);
    obj1.flatten(root2);
    obj2.flatten(root3);
    inorder(root1);cout<<endl;
    inorder(root2);cout<<endl;
    inorder(root3);cout<<endl;
}