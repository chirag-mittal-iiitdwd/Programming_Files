#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    TreeNode* right;
    TreeNode* left;
    int val;
    TreeNode(int data){
        right=NULL;
        left=NULL;
        val=data;
    }
};

class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> counts;
        vector<TreeNode*> ans;
        serialize(root, counts, ans);
        return ans;
    }
    string serialize(TreeNode* root, unordered_map<string, int>& counts, vector<TreeNode*>& ans) {
        if (!root) return "#";
        string key = to_string(root->val) + "," 
                     + serialize(root->left, counts, ans) + "," 
                     + serialize(root->right, counts, ans);
        counts[key]++;
        if (counts[key] == 2)
            ans.push_back(root);
        return key;
    }
};

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(2);
    root->right->left->left = new TreeNode(4);
    root->right->right = new TreeNode(4);
    Solution obj;
    vector<TreeNode*>x=obj.findDuplicateSubtrees(root);
    for(auto it:x){
        cout<<it->val<<" ";
    }
    cout<<endl;
    return 0;
}