/*
    Given a binary tree in array representation
            10 7 4 3 11 14 6
                  10
                 /  \
               /     \
              7      4
             / \    / \
            3   11 /  6 
                14  
            Parent Index = i
            Left son = 2 * i + 1
            Right son = 2 * i + 2
    1. Stating from root node
    2. Recursively call left and right with (HD -1) and (HD +1)
       as arguments
    Base case : When current node = NULL (return)
    3. Pushh the value into vector corresponding to the horizontal
       distance (HD).
    
    Map
    0   --> {10,11,14}
    -1  --> {7}
    -2  --> {3}
    1   --> {4}
    1   --> {6}
*/

#include<iostream>
#include<map>
#include<vector>
using namespace std;
class node{
    public:
    int key;
    node* left;
    node* right;
    node(int val){
        key=val;
        left=NULL;
        right=NULL;
    }
};

void getVerticalOrder(node* root,int hdis,map<int,vector<int>>&m){
    if(root==NULL){
        return ;
    }
    m[hdis].push_back(root->key);
    getVerticalOrder(root->left,hdis-1,m);
    getVerticalOrder(root->right,hdis+1,m);
}

int main(){
    node* root=new node(10);
    root->left=new node(7);
    root->right=new node(4);
    root->left->left=new node(3);
    root->left->right=new node(11);
    root->right->left=new node(14);
    root->right->right=new node(6);
    map<int,vector<int>> m;
    int hdis=0;
    getVerticalOrder(root,hdis,m);

    map<int,vector<int>>::iterator it;
    for(it=m.begin();it!=m.end();it++){
        cout<<it->first<<" ";
        for(int i=0;i<it->second.size();i++){
            cout<<(it->second)[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}