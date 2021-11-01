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

vector<int>verticalOrderTraversal(node*root){
    map<int,map<int,multiset<int>>>nodes;
    queue<pair<node*, pair<int, int>>> todo;
    todo.push({root,{0,0}});
    while(!todo.empty()){
        auto p=todo.front();
        todo.pop();
        node*n=p.first;
        int x=p.second.first,y=p.second.second;
        nodes[x][y].insert(n->data);
        if(n->left){
            todo.push({n->left,{x-1,y+1}});
        }
        if(n->right){
            todo.push({n->right,{x+1,y+1}});
        }
    }
    vector<int>ans;
    for(auto p:nodes){
        vector<int>col;
        for(auto q:p.second){
            col.insert(col.end(),q.second.begin(),q.second.end());
        }
        for(auto it:col){
            ans.insert(ans.end(),it);
        }
    }
    return ans;
}

/*
             1
           /  \
          2    3
         / \  / \
        4   5 6  7
*/

int main(){
    node*root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);

    vector<int>verticalOrder=verticalOrderTraversal(root);
    for(auto it:verticalOrder){
        cout<<it<<" ";
    }
    cout<<endl;
}