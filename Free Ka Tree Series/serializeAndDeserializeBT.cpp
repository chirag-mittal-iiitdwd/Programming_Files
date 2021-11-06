#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node*right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

class Solution{
    public:
    string serialize(node*root){
        string ans;
        if(root==NULL){
            return "#";
        }
        queue<node*>q;
        q.push(root);
        while(!q.empty()){
            node*top=q.front();
            q.pop();
            if(top!=NULL){
                ans+=to_string(top->data);
            }
            else{
                ans+="#";
            }

            if(top!=NULL){
                if(top->left!=NULL){
                    q.push(top->left);
                }
                else if(top->left==NULL){
                    q.push(NULL);
                }

                if(top->right!=NULL){
                    q.push(top->right);
                }
                else if(top->right==NULL){
                    q.push(NULL);
                }
            }
        }
        return ans;
    }

    node*deserialize(string serializedString){
        int i=0;
        node*root=new node(serializedString[i]-'0');
        i++;
        queue<node*>q;
        q.push(root);
        while(!q.empty()){
            node*top=q.front();
            q.pop();
            if(serializedString[i]=='#'){
                top->left=NULL;
                i++;
            }
            else{
                node*leftNode=new node(serializedString[i]-'0');
                top->left=leftNode;
                q.push(leftNode);
                i++;
            }

            if(serializedString[i]=='#'){
                top->right=NULL;
                i++;
            }
            else{
                node*rightNode=new node(serializedString[i]-'0');
                top->right=rightNode;
                q.push(rightNode);
                i++;
            }
        }
        return root;
    }
};

/*
             1
           /  \
          2    3
         / \  / \
        4   5 6  7
*/

void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    node*root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);

    Solution obj;
    string serializedStr=obj.serialize(root);
    node*root1=obj.deserialize(serializedStr);
    inorder(root1);cout<<endl;
}