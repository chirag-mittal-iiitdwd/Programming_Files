#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node*left;
    Node*right;
    Node(int data){
        val=data;
        left=NULL;
        right=NULL;
    }
};

class Solution {
    void rangeSumBST1(Node*&root, int&low, int&high,int&sum) {
        if(root==NULL){
            return ;
        }
        if(root->val<=high && root->val>=low){
            sum+=root->val;
        }
        if(root->val>=low){
            rangeSumBST1(root->left,low,high,sum);
        }
        if(root->val<=high){
            rangeSumBST1(root->right,low,high,sum);
        }
    }
    public:
    int rangeSumBST(Node*root,int low,int high){
        int sum=0;
        rangeSumBST1(root,low,high,sum);
        return sum;
    }
};

int main(){
    Node*root=new Node(10);
    root->left=new Node(5);
    root->right=new Node(15);
    root->right->right=new Node(18);
    root->left->left=new Node(3);
    root->left->right=new Node(7);

    Solution obj;
    cout<<obj.rangeSumBST(root,7,15)<<endl;
}