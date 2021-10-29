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

// Time Complexity : O(N) --> N is number of nodes
// Space Complexity : (N) --> In recursion
void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(node*root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

/*
    Level order traversal :
    Put root into queue
    than take the top of queue and insert it into vector and push left and right of current into queue
*/

vector<int>levelOrderTraversal(node*root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        node* top=q.front();
        q.pop();
        ans.push_back(top->data);
        if(top->left!=NULL){
            q.push(top->left);
        }
        if(top->right!=NULL){
            q.push(top->right);
        }
    }
    return ans;
}

// Time Complexity : O(N) --> N is number of nodes
// Space Complexity : (N) --> In stack, worst case when there is always one right node
// The intution for this code is that during recursion we used auxilary stack space why not create our own stack
vector<int>preorderIterative(node*root){
    stack<node*>st;
    st.push(root);
    vector<int>ans;
    while(!st.empty()){
        node* n=st.top();
        st.pop();
        ans.push_back(n->data);
        if(n->right!=NULL){
            st.push(n->right);
        }
        if(n->left!=NULL){
            st.push(n->left);
        }
    }
    return ans;
}

// Time Complexity : O(N) --> N is number of nodes
// Space Complexity : (N) --> In stack, worst case when it is a left squed tree
// The intution for this code is that during recursion we used auxilary stack space why not create our own stack
vector<int>inorderIterative(node*root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    stack<node*>st;
    node*n=root;
    while(true){
        if(n!=NULL){
            // If current is not null than we push it into stack because we need to print it after all left nodes
            st.push(n);
            n=n->left;
        }
        else{
            if(st.empty()){
                break;
            }
            n=st.top();
            st.pop();

            // If all the left nodes are empty than we push the data of current node which we stored in if block
            ans.push_back(n->data);
            n=n->right;
        }
    }
    return ans;
}

vector<int>postorderIterative2Stacks(node*root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    stack<node*>st1,st2;
    st1.push(root);
    while(!st1.empty()){
        node*n=st1.top();
        st1.pop();
        st2.push(n);
        if(n->left!=NULL){
            st1.push(n->left);
        }
        if(n->right!=NULL){
            st1.push(n->right);
        }
    }
    while(!st2.empty()){
        ans.push_back(st2.top()->data);
        st2.pop();
    }
    return ans;
}

vector<int>postorderIterative1Stack(node*root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    stack<node*>st;
    node*curr=root;
    while(curr!=NULL || !st.empty()){

        // Going to the left most node possible
        if(curr!=NULL){
            st.push(curr);
            curr=curr->left;
        }
        else{
            node*temp=st.top()->right;
            if(temp==NULL){
                temp=st.top();
                st.pop();
                ans.push_back(temp->data);
                while(!st.empty() && temp==st.top()->right){
                    temp=st.top();
                    st.pop();
                    ans.push_back(temp->data);
                }
            }
            else{
                curr=temp;
            }
        }
    }
    return ans;
}

/*
    Preorder/ Indorder/ Postorder Traversal in one go
    taking three lists or vectors for preorder, inorder and postorder
    stack<pair<node,num>> is to be constructed

    when starting off take (root,1) and push into stack
    while taking out from stack if(num==1) goes to preorder, push number by doing ++, and if left exists then enter that left
    if num==2 --> inorder ++ and right
    if num==3 --> postorder
    now take out the element
*/

vector<vector<int>> allThreeTraversalInOne(node*root){
    vector<vector<int>>ans;
    stack<pair<node*,int>>st;
    vector<int>preO,inO,postO;
    st.push({root,1});
    if(root==NULL){
        return ans;
    }
    while(!st.empty()){
        auto it=st.top();
        st.pop();
        if(it.second==1){
            preO.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->left!=NULL){
                st.push({it.first->left,1});
            }
        }
        else if(it.second==2){
            inO.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->right!=NULL){
                st.push({it.first->right,1});
            }
        }
        else{
            postO.push_back(it.first->data);
        }
    }
    ans.push_back(preO);
    ans.push_back(inO);
    ans.push_back(postO);
    return ans;
}

/*
             1
           /  \
          2    3
         / \  / \
        4   5 6  7
*/

int main(){
    node*root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);

    cout<<"Preorder : ";
    preorder(root);
    cout<<endl;
    cout<<"Preorder : ";
    vector<int>preorderIter=preorderIterative(root);
    for(auto it:preorderIter){
        cout<<it<<" ";
    }
    cout<<endl;

    cout<<"Inorder : ";
    inorder(root);
    cout<<endl;
    cout<<"Inorder : ";
    vector<int>inorderIter=inorderIterative(root);
    for(auto it:inorderIter){
        cout<<it<<" ";
    }
    cout<<endl;

    cout<<"Postorder : ";
    postorder(root);
    cout<<endl;
    cout<<"Postorder : ";
    for(auto it:postorderIterative2Stacks(root)){
        cout<<it<<" ";
    }
    cout<<endl;
    cout<<"Postorder : ";
    for(auto it:postorderIterative1Stack(root)){
        cout<<it<<" ";
    }
    cout<<endl;
    cout<<"Level Order : ";
    vector<int>levelOrder=levelOrderTraversal(root);
    for(auto it:levelOrder){
        cout<<it<<" ";
    }
    cout<<endl;

    cout<<"\n \nAll three traversals at the same time\n1.Preorder\n2.Inorder\n3.Postorder\n";
    vector<vector<int>>allInOne=allThreeTraversalInOne(root);
    for(auto it:allInOne){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}