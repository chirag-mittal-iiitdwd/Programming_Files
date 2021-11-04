/*
    The main problem here is that we can t move in reverse order
    we need to sort that our for that we will make a map which stores nodes's parent

    after that to prevent back movenment of traversal of nodes we make a visited map
    after that we move radially outward 
    and if we hit the required k value then we break and transfer everthing into a vector and return
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

class Solution{
    void markParents(node*root,unordered_map<node*,node*>&parent){
        queue<node*>q;
        q.push(root);
        while(!q.empty()){
            node* currentNode=q.front();
            q.pop();
            if(currentNode->left){
                q.push(currentNode->left);
                parent[currentNode->left]=currentNode;
            }
            if(currentNode->right){
                q.push(currentNode->right);
                parent[currentNode->right]=currentNode;
            }
        }
    }
    public:
    vector<int>nodesAtK(node*target,node*root,int k){
        unordered_map<node*,node*>parent;
        markParents(root,parent);

        unordered_map<node*,bool>visited;
        queue<node*>q;
        visited[target]=true;
        int cur_level=0;
        q.push(target);
        while(!q.empty()){
            int size=q.size();
            if(cur_level==k){
                break;
            }
            cur_level++;
            for(int i=0;i<size;i++){
                node*current=q.front();
                q.pop();
                if(current->left && !visited[current->left]){
                    q.push(current->left);
                    visited[current->left]=true;
                }
                if(current->right && !visited[current->right]){
                    q.push(current->right);
                    visited[current->right]=true;
                }
                if(parent[current] && !visited[parent[current]]){
                    q.push(parent[current]);
                    visited[parent[current]]=true;
                }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front()->data);
            q.pop();
        }
        return ans;
    }
};

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

    Solution obj;
    vector<int>nodesAtK1=obj.nodesAtK(root->left,root,1);
    for(auto it:nodesAtK1){
        cout<<it<<" ";
    }
    cout<<endl;
}