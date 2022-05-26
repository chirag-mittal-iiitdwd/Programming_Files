#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL){
            return NULL;
        }

        queue<Node*>q;
        q.push(root);

        while(!q.empty()){
            int size=q.size();
            Node*next=NULL;
            for(int i=0;i<size;i++){
                if(q.front()->right!=NULL){
                    q.push(q.front()->right);
                }
                if(q.front()->left!=NULL){
                    q.push(q.front()->left);
                }
                q.front()->next=next;
                next=q.front();
                q.pop();
            }
        }

        return root;
    }
};