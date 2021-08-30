// If we print left to right on first level. 
// Than we have to print right to left on second level and so on
/*
----->
1. Use 2 stacks - currentLevel & nextLevel
2. variable (bool type) -leftToRight(true initially)
3. if leftToRight, push left child then right
    else, push right child then left
*/

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

void zigzagTreversal(node* root){
    if(root==NULL){
        return;
    }

    stack<node*> currLevel;
    stack<node*> nextLevel;
    bool leftToRight=true;
    currLevel.push(root);
    while(!currLevel.empty()){
        node* temp=currLevel.top();
        currLevel.pop();

        // If temp is not NULL than only we would we able to check left and right
        if(temp){
            cout<<temp->data<<" ";
            
            // When we went from leftToRight in previous level
            if(leftToRight){
                if(temp->left){
                    // First we are pushing left because we want
                    // right to pop first
                    nextLevel.push(temp->left);
                }
                if(temp->right){
                    nextLevel.push(temp->right);
                }
            }
            // When we went rightToLeft in previous level
            else{
                if(temp->right){
                    nextLevel.push(temp->right);
                }
                if(temp->left){
                    nextLevel.push(temp->left);
                }
            }
        }

        if(currLevel.empty()){
            leftToRight=!leftToRight;
            swap(currLevel,nextLevel);
        }
    }
}

int main(){
    /*
            12
           /  \
          9    15
         / \
        5   10
    */

    node* root=new node(12);
    root->left=new node(9);
    root->left->left=new node(5);
    root->left->right=new node(10);
    root->right=new node(15);
    zigzagTreversal(root);
    cout<<endl;
}