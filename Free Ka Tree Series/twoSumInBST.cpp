#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node*left;
    node*right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

/*
    This is the most optimised approach
    Time Complexity : O(N)
    Space Complexity : 2 O(H)

    Could have also stored everything in a vector 
    and then calculated two sum but that would cost
    Time Complexity : O(N)
    Space Complexity : O(N)
*/
class BSTiterator{
    stack<node*>st;
    // reverse -> true -> before
    // reverse -> false -> next
    bool reverse = true;
    void pushAll(node*root){
        while(root!=NULL){
            st.push(root);
            if(reverse==true){
                root=root->right;
            }
            else{
                root=root->left;
            }
        }
    }
    public:
    BSTiterator(node*root,bool isReverse){
        reverse = isReverse;
        pushAll(root);
    }
    bool hasNext(){
        return !st.empty();
    }
    int next(){
        node*temp=st.top();
        st.pop();
        if(!reverse){
            pushAll(temp->right);
        }
        else{
            pushAll(temp->left);
        }
        return temp->data;
    }
};

class Solution{
    public:
    bool findTarget(node*root,int k){
        if(!root){
            return false;
        }
        BSTiterator l(root,false);
        BSTiterator r(root,true);
        int i=l.next();
        int j=r.next();
        while(i<j){
            if(i+j==k){
                return true;
            }
            else if(i+j<k){
                i=l.next();
            }
            else{
                j=r.next();
            }
        }
        return false;
    }
};

int main(){
    node*root=new node(7);
    root->left=new node(3);
    root->left->left=new node(2);
    root->left->left->left=new node(1);
    root->left->right=new node(6);
    root->left->right->left=new node(5);
    root->left->right->left->left=new node(4);
    root->right=new node(10);
    root->right->right=new node(11);
    root->right->left=new node(9);
    root->right->left->left=new node(8);

    Solution obj;
    cout<<obj.findTarget(root,2);
}