#include<bits\stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node*right;
    node*left;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

class Solution{
    public:
    int maxWidthOgBinaryTree(node*root){
        if(!root) return 0;
        int ans=0;
        queue<pair<node*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            int minIdx=q.front().second;
            int first,second;
            for(int i=0;i<size;i++){
                int cur_id=q.front().second-minIdx;
                node*n=q.front().first;
                q.pop();
                if(i==0) first=cur_id;
                if(i==size-1) second=cur_id;
                if(n->left){
                    q.push({n->left,cur_id*2+1});
                }
                if(n->right){
                    q.push({n->right,cur_id*2+2});
                }
            }
            ans=max(ans,second-first+1);
        }
        return ans;
    }
};

int main(){
    node*root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);

    Solution obj;
    cout<<obj.maxWidthOgBinaryTree(root)<<endl;
}