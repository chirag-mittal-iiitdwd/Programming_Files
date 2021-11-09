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
    Using Morris Traversal
    Time : O(N)
    Space : O(1)
*/
int kthSmallestElement(node*root,int k){
    node*cur=root;
    int cnt=0;
    while(cur!=NULL){
        if(cur->left==NULL){
            cnt++;
            if(cnt==k){
                return cur->data;
            }
            cur=cur->right;
        }
        else{
            node*prev=cur->left;
            while(prev->right && prev->right!=cur){
                prev=prev->right;
            }
            if(prev->right==NULL){
                prev->right=cur;
                cur=cur->left;
            }
            else{
                prev->right=NULL;
                cnt++;
                if(cnt==k){
                    return cur->data;
                }
                cur=cur->right;
            }
        }
    }
    return -1;
}

/*
    Using recursion
    Time : O(N)
    Space : O(N)
*/
class Solution{
    int ans=INT_MIN;
    void inorder(node*root,int k){
        static int x=0;
        if(root==NULL){
            return;
        }
        inorder(root->left,k);
        x++;
        if(x==k){
            ans=root->data;
            return;
        }
        inorder(root->right,k);
    }
    public:
    int kthSmallestElement(node*root,int k){
        inorder(root,k);
        return ans;
    }
};

int main(){
    // node*root=new node(5);
    // root->left=new node(3);
    // root->left->left=new node(1);
    // root->left->right=new node(4);
    // root->left->left->right=new node(2);
    // root->right=new node(7);
    // root->right->right=new node(8);
    // root->right->left=new node(6);
    node*root=new node(2);
    root->left=new node(1);
    root->right=new node(3);
    root->right->right=new node(4);

    Solution ob;
    cout<<ob.kthSmallestElement(root,1)<<endl;
    cout<<kthSmallestElement(root,1)<<endl;
}