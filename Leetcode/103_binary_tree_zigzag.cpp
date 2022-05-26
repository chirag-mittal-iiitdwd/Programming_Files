#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL){
            return ans;
        }

        bool isLeft=true;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>v;
            for(int i=0;i<size;i++){
                TreeNode*top=q.front();
                q.pop();
                if(top->left!=NULL){
                    q.push(top->left);
                }
                if(top->right!=NULL){
                    q.push(top->right);
                }
                v.push_back(top->val);
            }
            if(isLeft){
                ans.push_back(v);
                isLeft=false;
            }
            else{
                reverse(v.begin(),v.end());
                ans.push_back(v);
                isLeft=true;
            }
        }

        return ans;
    }
};