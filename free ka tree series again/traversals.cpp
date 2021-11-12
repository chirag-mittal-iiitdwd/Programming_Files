#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node*left;
    node*right;
    node(int val){
        data=val;
        left=right=NULL;
    }
};

class inorderRec{
    void inorder(node*root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
    public:
    void printInorder(node*root){
        cout<<"Inorder : ";
        inorder(root);
        cout<<endl;
    }
};

class preorderRec{
    void preorder(node*root){
        if(root==NULL){
            return;
        }
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
    public:
    void printPreorder(node*root){
        cout<<"Preorder : ";
        preorder(root);
        cout<<endl;
    }
};

class postorderRec{
    void postorder(node*root){
        if(root==NULL){
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
    public:
    void printPostorder(node*root){
        cout<<"Postorder : ";
        postorder(root);
        cout<<endl;
    }
};

class preorderIter{
    public:
    vector<int>preorder(node*root){
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        stack<node*>st;
        st.push(root);
        while(!st.empty()){
            node*n=st.top();
            ans.push_back(n->data); // In preorder we want the data of root first
            st.pop();
            if(n->right){ // Pushing right first because we want left to be poped out first as stack follows LIFO
                st.push(n->right);
            }
            if(n->left){
                st.push(n->left);
            }
        }
        return ans;
    }
};

class inorderIter{
    public:
    vector<int>inorder(node*root){
        vector<int>ans;
        stack<node*>st;
        node*n=root;

        // Keep running the loop till inf
        // The break condition will be when the stack is empty
        // initially also the stack is empty but there can be case when the root is NULL
        // so when root is NULL the loop will break on first run
        while(true){

            // Checking if current node is NULL or not
            // If it is NULL that means we might have traversed entire left subtree
            // Than in that case move to right and again check for left
            if(n){
                st.push(n);
                n=n->left;
            }
            else{
                if(st.empty()){
                    break;
                }
                n=st.top();
                st.pop();
                ans.push_back(n->data);
                n=n->right;
            }
        }
        return ans;
    }
};

class postorderIter2Stack{
    public:
    vector<int>postorder(node*root){
        stack<node*>st1,st2;
        vector<int>ans;
        if(root==NULL){
            return ans;
        }

        // Pushing the root onto the stack1
        st1.push(root);
        while(!st1.empty()){
            node*n=st1.top();
            st1.pop();

            // Taking the current stack1 top into stack2
            st2.push(n);
            if(n->left){
                st1.push(n->left);
            }
            if(n->right){
                st1.push(n->right);
            }
        }

        // Now stack2 contains the preorder in reverse order
        while(!st2.empty()){
            ans.push_back(st2.top()->data);
            st2.pop();
        }
        return ans;
    }
};

class postorderIter1Stack{
    public:
    vector<int>postorder(node*root){
        stack<node*>st;
        vector<int>ans;
        node*curr=root;
        while(curr && !st.empty()){
            if(curr){
                // currently going to extreme left
                st.push(curr);
                curr=curr->left;
            }else{

                // taking the stacks top right to temp
                node*temp=st.top()->right;
                if(temp==NULL){
                    // If temp is NUll this means that our traversal has reached at the end of left and right
                    // now we need to take the value into the answer
                    temp=st.top();
                    st.pop();
                    ans.push_back(temp->data); // Thus taking the value
                    while(!st.empty()&&temp==st.top()->right){
                        // going back from extreme right towards root
                        // If there are nodes which are left to be taken
                        // Basically checking if there was any root for the current node
                        // We need to take root
                        temp=st.top();
                        st.pop();
                        ans.push_back(temp->data);
                    }
                }
                else{
                    // If the temp is not NUll this means there can be more left nodes of current nodes so we need to take those first
                    curr=temp;
                }
            }
        }
        return ans;
    }
};

class zigZag{
    bool flag=true;
    public:
    vector<int>zigZagTrav(node*root){
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        queue<node*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>res;
            for(int i=0;i<size;i++){
                node*n=q.front();
                q.pop();
                res.push_back(n->data);
                if(n->left){
                    q.push(n->left);
                }
                if(n->right){
                    q.push(n->right);
                }
            }
            if(flag){
                for(auto it:res){
                    ans.push_back(it);
                }
                flag=false;
            }
            else{
                reverse(res.begin(),res.end());
                for(auto it:res){
                    ans.push_back(it);
                }
                flag=true;
            }
        }
        return ans;
    }
};

class levelOrderTraversal{
    public:
    vector<int>levelOrder(node*root){
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        queue<node*>q;
        q.push(root);
        while(!q.empty()){
            node*n=q.front();
            q.pop();
            ans.push_back(n->data);
            if(n->left){
                q.push(n->left);
            }
            if(n->right){
                q.push(n->right);
            }
        }
        return ans;
    }
};

class allDFS{
    public:
    vector<vector<int>>allTraversals(node*root){
        vector<vector<int>>ans;
        if(root==NULL){
            return ans;
        }
        vector<int>preO;
        vector<int>postO;
        vector<int>inO;
        stack<pair<node*,int>>st;
        st.push({root,1});
        while(!st.empty()){
            auto p=st.top();
            st.pop();
            node*n=p.first;
            if(p.second==1){
                preO.push_back(n->data);
                p.second++;
                st.push(p);
                if(n->left){
                    st.push({n->left,1});
                }
            }
            else if(p.second==2){
                inO.push_back(n->data);
                p.second++;
                st.push(p);
                if(n->right){
                    st.push({n->right,1});
                }
            }
            else{
                postO.push_back(n->data);
            }
        }
        ans.push_back(preO);
        ans.push_back(inO);
        ans.push_back(postO);
        return ans;
    }
};

class heightOfBT{
    public:
    int height(node*root){
        if(root==NULL){
            return 0;
        }
        int lh=height(root->left);
        int rh=height(root->right);
        return max(lh,rh)+1;
    }
};

class diameter{
    int height(node*root){
        if(root==NULL){
            return 0;
        }
        int lh=height(root->left);
        int rh=height(root->right);
        return max(lh,rh)+1;
    }
    int heightForDiaOpti(node*root,int &dia){
        if(root==NULL){
            return 0;
        }
        int lh=heightForDiaOpti(root->left,dia);
        int rh=heightForDiaOpti(root->right,dia);
        dia=max(dia,lh+rh+1);
        return max(lh,rh)+1;
    }
    public:
    int diameterBrute(node*root){
        if(root==NULL){
            return 0;
        }
        int lh=height(root->left);
        int rh=height(root->right);
        int lDia=diameterBrute(root->left);
        int rDia=diameterBrute(root->right);
        return max(lDia,max(rDia,lh+rh+1));
    }
    int diameterOpti(node*root){
        int dia=0;
        heightForDiaOpti(root,dia);
        return dia;
    }
};

class isBTBalanced{
    int isBalancedBt(node*root){
        if(root==NULL){
            return 0;
        }
        int lh=isBalancedBt(root->left);
        int rh=isBalancedBt(root->right);
        if(lh==-1||rh==-1||abs(lh-rh)>1){
            return -1;
        }
        return 1+max(lh,rh);
    }
    public:
    bool isBalanced(node*root){
        if(isBalancedBt(root)==-1){
            return false;
        }
        else{
            return true;
        }
    }
};

// Check maximum path sum

class boundaryTraversal{
    bool isLeaf(node*root){
        return (!root->left)&&(!root->right);
    }
    void addLeftBoundry(node*root,vector<int>&ans){
        node*cur=root->left;
        while(cur){
            if(!isLeaf(cur)){
                ans.push_back(cur->data);
            }
            cur=cur->left?cur->left:cur->right;
        }
    }
    void addRightBoundry(node*root,vector<int>&ans){
        node*cur=root->right;
        vector<int>res;
        while(cur){
            if(!isLeaf(cur)){
                res.push_back(cur->data);
            }
            cur=cur->right?cur->right:cur->left;
        }
        reverse(res.begin(),res.end());
        for(auto it:res){
            ans.push_back(it);
        }
    }
    void addLeaves(node*root,vector<int>&ans){
        if(isLeaf(root)){
            ans.push_back(root->data);
        }
        if(root->left){
            addLeaves(root->left,ans);
        }
        if(root->right){
            addLeaves(root->right,ans);
        }
    }
    public:
    vector<int>boundary(node*root){
        vector<int>ans;
        if(!isLeaf(root)){
            ans.push_back(root->data);
        }
        addLeftBoundry(root,ans);
        addLeaves(root,ans);
        addRightBoundry(root,ans);
        return ans;
    }
};

class verticalOrder{
    public:
    vector<int>verticalOrderTrav(node*root){
        map<int,map<int,multiset<int>>>mp;
        queue<pair<node*,pair<int,int>>>q;
        vector<int>ans;
        if(!root){
            return ans;
        }
        q.push({root,{0,0}});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            node*n=it.first;
            int x=it.second.first;
            int y=it.second.second;
            mp[x][y].insert(n->data);
            if(n->left){
                q.push({n->left,{x-1,y+1}});
            }
            if(n->right){
                q.push({n->right,{x+1,y+1}});
            }
        }
        for(auto p:mp){
            vector<int>col;
            for(auto q:p.second){
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            for(auto it:col){
                ans.push_back(it);
            }
        }
        return ans;
    }
};