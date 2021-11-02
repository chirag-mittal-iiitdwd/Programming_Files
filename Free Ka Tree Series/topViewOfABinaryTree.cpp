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


// Failing for some testcases
// class Solution{
//     void leftnodes(node*root,vector<int>&main){
//         vector<int>ans;
//         node*cur=root->left;
//         while(cur){
//             ans.push_back(cur->data);
//             if(cur->left){
//                 cur=cur->left;
//             }
//             else{
//                 if(cur->right){
//                     cur=cur->right;
//                 }
//                 else{
//                     break;
//                 }
//             }
//         }
//         reverse(ans.begin(),ans.end());
//         for(auto it:ans){
//             main.push_back(it);
//         }
//     }
//     void rightnodes(node*root,vector<int>&ans){
//         node*cur=root->right;
//         while(cur){
//             ans.push_back(cur->data);
//             if(cur->right){
//                 cur=cur->right;
//             }
//             else{
//                 if(cur->left){
//                     cur=cur->left;
//                 }
//                 else{
//                     break;
//                 }
//             }
//         }
//     }
//     public:
//     vector<int> topView(node*root){
//         vector<int>ans;
//         if(root==NULL){
//             return ans;
//         }
//         else{
//             leftnodes(root,ans);
//             ans.push_back(root->data);
//             rightnodes(root,ans);
//         }
//         return ans;
//     }
// };

class Solution{
    public:
    vector<int> topView(node *root){
        vector<int> ans; 
        if(root == NULL) return ans; 
        map<int,int> mpp; 
        queue<pair<node*, int>> q; 
        q.push({root, 0}); 
        while(!q.empty()) {
            auto it = q.front(); 
            q.pop(); 
            node* n = it.first; 
            int line = it.second; 
            if(mpp.find(line) == mpp.end()) mpp[line] = n->data; 
            
            if(n->left != NULL) {
                q.push({n->left, line-1}); 
            }
            if(n->right != NULL) {
                q.push({n->right, line + 1}); 
            }
            
        }
        for(auto it : mpp) {
            ans.push_back(it.second); 
        }
        return ans; 
    }

};

class Solution2 {
  public:
    vector <int> bottomView(node *root) {
        vector<int> ans; 
        if(root == NULL) return ans; 
        map<int,int> mpp; 
        queue<pair<node*, int>> q; 
        q.push({root, 0}); 
        while(!q.empty()) {
            auto it = q.front(); 
            q.pop(); 
            node*n = it.first; 
            int line = it.second; 
            mpp[line] = n->data; 
            
            if(n->left != NULL) {
                q.push({n->left, line-1}); 
            }
            if(n->right != NULL) {
                q.push({n->right, line + 1}); 
            }
            
        }
        
        for(auto it : mpp) {
            ans.push_back(it.second); 
        }
        return ans;  
    }
};

// Incorrect Code
// class Solution3{
//     public:
//     vector<int>rightView(node*root){
//         vector<int>ans;
//         if(root==NULL){
//             return ans;
//         }
//         queue<pair<node*,int>>q;
//         map<int,node*>mp;
//         q.push({root,0});
//         while(!q.empty()){
//             auto p=q.front();
//             q.pop();
//             node*n=p.first;
//             int x=p.second;
//             if(mp.find(x)==mp.end()){
//                 mp[x]=n;
//             }
//             if(n->left){
//                 q.push({n->left,x-1});
//             }
//             if(n->right){
//                 q.push({n->right,x+1});
//             }
//         }
//         for(auto it:mp){
//             if(it.first>=0){
//                 ans.push_back(it.second->data);
//             }
//         }
//         return ans;
//     }
// };

class Solution3{
    void mainLogic(node*root,int level,vector<int>&ans){
        if(root==NULL){
            return;
        }
        if(ans.size()==level){
            ans.push_back(root->data);
        }
        mainLogic(root->right,level+1,ans);
        mainLogic(root->left,level+1,ans);
    }
    public:
    vector<int>rightView(node*root){
        vector<int>ans;
        mainLogic(root,0,ans);
        return ans;
    }
};

class Solution4{
    void mainLogic(node*root,int level,vector<int>&res){
        if(root==NULL){
            return;
        }
        if(res.size()==level){
            res.push_back(root->data);
        }
        mainLogic(root->left,level+1,res);
        mainLogic(root->right,level+1,res);
    }
    public:
    vector<int>leftView(node*root){
        vector<int>res;
        mainLogic(root,0,res);
        return res;
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
    Solution ob;
    vector<int>top=ob.topView(root);
    for(auto it:top){
        cout<<it<<" ";
    }
    cout<<endl;

    Solution2 bt;
    cout<<"Bottom View : ";
    for(auto it:bt.bottomView(root)){
        cout<<it<<" ";
    }
    cout<<endl;

    Solution3 rv;
    cout<<"Right view : ";
    vector<int>right=rv.rightView(root);
    for(auto it:right){
        cout<<it<<" ";
    }
    cout<<endl;

    Solution4 lv;
    cout<<"Left View : ";
    vector<int>leftviewarr=lv.leftView(root);
    for(auto it:leftviewarr){
        cout<<it<<" ";
    }
    cout<<endl;
}