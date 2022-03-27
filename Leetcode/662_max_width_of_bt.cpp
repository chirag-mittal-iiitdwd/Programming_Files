#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        queue<pair<TreeNode*,long long int>>q;
        q.push({root,0});
        int ans=0;
        while(!q.empty()){
            long long int size=q.size();
            long long int mmin=q.front().second;
            int first,last;
            for(long long int i=0;i<size;i++){
                long long int cur_id=q.front().second-mmin;
                TreeNode*n=q.front().first;
                q.pop();
                if(i==0){
                    first=cur_id;
                }
                if(i==(size-1)){
                    last=cur_id;
                }
                if(n->left){
                    q.push({n->left,cur_id*2+1});
                }
                if(n->right){
                    q.push({n->right,cur_id*2+2});
                }
            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};