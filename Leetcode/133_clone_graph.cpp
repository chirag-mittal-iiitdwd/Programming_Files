#include<bits/stdc++.h>
using namespace std;

class Solution {
    Node*dfs(Node*node,unordered_map<Node*,Node*>&mp){
        if(mp.find(node)!=mp.end()){
            return mp[node];
        }
        Node*clone=new Node(node->val);
        mp[node]=clone;
        for(auto&it:node->neighbors){
            clone->neighbors.push_back(dfs(it,mp));
        }
        return clone;
    }
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL){
            return node;
        }
        unordered_map<Node*,Node*>mp;
        return dfs(node);
    }
};