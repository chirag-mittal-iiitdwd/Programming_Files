/*
    Here we use level order traversal because we burn the nodes in level order
*/
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node*left;
    node*right;
    node(int val){
        data=val;
        right=NULL;
        left=NULL;
    }
};

class burnTree{
    void parentNodes(unordered_map<node*,node*>&mp,node*root){
        queue<node*>q;
        q.push(root);
        while(!q.empty()){
            node*current=q.front();
            q.pop();
            if(current->left){
                q.push(current->left);
                mp[current->left]=current;
            }
            if(current->right){
                q.push(current->right);
                mp[current->right]=current;
            }
        }
    }
    public:
    int burnTheTree(node*root,node*target){
        unordered_map<node*,node*>parent;
        parentNodes(parent,root);
        unordered_map<node*,bool>visited;
        queue<node*>q;
        visited[target]=true;
        q.push(target);
        int time=0;
        while(!q.empty()){
            int size=q.size();
            int cnt=0;
            for(int i=0;i<size;i++){
                node*current=q.front();
                q.pop();
                if(current->left && !visited[current->left]){
                    q.push(current->left);
                    visited[current->left]=true;
                    cnt++;
                }
                if(current->right && !visited[current->right]){
                    q.push(current->right);
                    visited[current->right]=true;
                    cnt++;
                }
                if(parent[current] && !visited[parent[current]]){
                    q.push(parent[current]);
                    visited[parent[current]]=true;
                    cnt++;
                }
            }
            if(cnt!=0){
                time++;
            }
        }
        return time;
    }
};

int main(){
    node*root=new node(1);
    root->left=new node(2);
    root->left->left=new node(4);
    root->left->left->right=new node(7);
    root->right=new node(3);
    root->right->left=new node(5);
    root->right->right=new node(6);

    burnTree obj;
    cout<<obj.burnTheTree(root,root->left->left->right);
}