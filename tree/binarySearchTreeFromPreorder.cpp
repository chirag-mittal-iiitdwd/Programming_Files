// Setting a minimum and maximum value of each element of the array
/* here the numbers in the brackets are of the form
                (min,max)
                N --> NULL     
                     |
                     |
            This is preorder sequence     
array ---->  7  ,  5  ,  4  ,  6  ,  8  ,  9
           (N,N) (N,7) (N,5) (5,7) (7,N) (8,N)
                        

                      (7,N)
              (N,7) 7 <-| 8 added here  (8,N)
                   /                        \
            (N,5) 5 (5,7) <--- 6 added here   9
                 /
          (N,4) 4 (4,5) 
*/

#include<iostream>
#include<climits>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

node* constructBST(int preorder[],int* preorderIdx,int key,int min,int max,int n){
    if(*preorderIdx>=n){
        return NULL;
    }
    node* root=NULL;
    // If this condition does not satisfy than we return NULL
    if(key>min && key<max){
        root=new node(key);
        *preorderIdx=*preorderIdx+1;
        if(*preorderIdx<n){
            // This will built entire left subtree
            root->left=constructBST(preorder,preorderIdx,preorder[*preorderIdx],min,key,n);
        }
        if(*preorderIdx<n){
            // This will built entire right subtree
            root->right=constructBST(preorder,preorderIdx,preorder[*preorderIdx],key,max,n);
        }
    }

    return root;
}

void inorderPrint(node* root){
    if(root==NULL){
        return;
    }
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

int main(){
    /*
            10
           /  \
          2    13
         /    /
        1    11 
    */
    int preorder[]={10,2,1,13,11};
    int n=5;
    int preorderIdx=0;
    node* root=constructBST(preorder,&preorderIdx,preorder[0],INT_MIN,INT_MAX,n);
    inorderPrint(root);
    cout<<endl;
}