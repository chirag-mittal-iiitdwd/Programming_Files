#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*left;
    Node*right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

class Solution {
    int ans=0;
    int helper(Node*root){
        int left=(root->left?helper(root->left):0);
        int right=(root->right?helper(root->right):0);
        ans+=abs(left-right);
        return left+right+root->data;
    }
public:
    int findTilt(Node* root) {
        helper(root);
        return ans;
    }
};

int main(){
    Node*root=new Node(4);
    root->left=new Node(2);
    root->left->left=new Node(3);
    root->left->right=new Node(5);
    root->right=new Node(9);
    root->right->right=new Node(7);
    Solution onj;
    cout<<onj.findTilt(root);
}