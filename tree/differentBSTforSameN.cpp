#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* right;
    node* left;
    node(int val){
        data=val;
        right=NULL;
        left=NULL;
    }
};

vector<node*> constructTrees(int start,int end){
    vector<node*> trees;
    if(start>end){
        trees.push_back(NULL);
        return trees;
    }
    for(int i=start;i<=end;i++){
        vector<node*> leftSubtree=constructTrees(start,i-1);
        vector<node*> rightSubtree=constructTrees(i+1,end);
        // Now combining them
        for(int j=0;j<leftSubtree.size();j++){
            node* leftN=leftSubtree[j];
            for(int k=0;k<rightSubtree.size();k++){
                node* rightN=rightSubtree[k];
                node* node1=new node(i);
                node1->left=leftN;
                node1->right=rightN;
                trees.push_back(node1);
            }
        }
    }
    return trees;
}

void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    vector<node*> totalTrees=constructTrees(1,3);
    for(int i=0;i<totalTrees.size();i++){
        cout<<(i+1)<<" : ";
        preorder(totalTrees[i]);
        cout<<endl;
    }
}