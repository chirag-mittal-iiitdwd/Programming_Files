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

/*
    Time Complexity : O(N) 
    In the code we are traversing throught the right branch of every node so it will together add upto N

    Space Complexity : (1)
*/
vector<int>morrisTraversal(node*root){
    vector<int>inorder;
    node*cur=root;
    while(cur!=NULL){
        if(cur->left==NULL){
            // Meaning we have traversed the entire left subtree or there was no left subtree
            // So we need to take current node's data which will be behaving as root
            // Then we would move towards the right in the tree
            // Because in inorder it's LEFT, ROOT , RIGHT
            inorder.push_back(cur->data);
            cur=cur->right;
        }
        else{
            node*prev=cur->left;
            // Go to the rightmost node of cur->left
            while(prev->right && prev->right!=cur){
                // If right node is not null and there is no link between the current node and cur
                // This means this is not the lastmost right node
                prev=prev->right;
            }
            if(prev->right==NULL){
                // If we have reached to the end of rightmost node than we need to change the link now the right must point to cur for returning
                prev->right=cur;

                // After doing this going more deep
                cur=cur->left;
            }
            else{

                // Basically here there will be two links either both of them exits or one can be NULL
                // First we break the last link and we take its data and then we go to previous of which was deleted
                prev->right=NULL;  // Breaking the link
                inorder.push_back(cur->data);  // Taking the data
                cur=cur->right; 
                // Here we are moving to the link of prev->right=cur which we created in the if block of the code
            }
        }
    }
    return inorder;
}

vector<int>morrisTraversalPreorder(node*root){
    vector<int>preorder;
    node*cur=root;
    while(cur!=NULL){
        if(cur->left==NULL){
            preorder.push_back(cur->data);
            cur=cur->right;
        }
        else{
            node*prev=cur->left;
            while(prev->right && prev->right!=cur){
                prev=prev->right;
            }
            if(prev->right==NULL){
                prev->right=cur;
                preorder.push_back(cur->data);
                // Befre moving to the left pushing the cur or ROOT into the preorder
                cur=cur->left;
            }
            else{
                prev->right=NULL;
                cur=cur->right; 
            }
        }
    }
    return preorder;
}

int main(){
    node*root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);

    vector<int>inorder=morrisTraversal(root);
    vector<int>preorder=morrisTraversalPreorder(root);

    cout<<"Inorder : ";
    for(auto it:inorder){
        cout<<it<<" ";
    }
    cout<<endl;

    cout<<"PreOrder : ";
    for(auto it:preorder){
        cout<<it<<" ";
    }
    cout<<endl;
}