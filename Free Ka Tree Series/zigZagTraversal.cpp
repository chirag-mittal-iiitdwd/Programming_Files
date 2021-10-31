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

vector<int>zigZagTraversal(node*root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    bool flag=true;
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        vector<node*>temp;
        int n=q.size();
        for(int i=0;i<n;i++){
            node*top=q.front();
            q.pop();
            if(top->left!=NULL){
                q.push(top->left);
            }
            if(top->right!=NULL){
                q.push(top->right);
            }
            temp.push_back(top);
        }
        if(flag){
            flag=false;
            reverse(temp.begin(),temp.end());
            for(int i=0;i<temp.size();i++){
                ans.push_back(temp[i]->data);
            }
        }
        else{
            flag=true;
            for(int i=0;i<temp.size();i++){
                ans.push_back(temp[i]->data);
            }
        }
    }
}

int main(){
    node*root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    vector<int>zigZag=zigZagTraversal(root);
    for(auto it:zigZag){
        cout<<it<<" ";
    }
    cout<<endl;
}