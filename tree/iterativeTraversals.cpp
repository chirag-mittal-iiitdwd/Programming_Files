#include <iostream>
#include <stack>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preorderIter(node *root)
{
    stack<node *> st;
    while (root || !st.empty())
    {
        if (root)
        {
            cout << root->data << " ";
            st.push(root);
            root = root->left;
        }
        else
        {
            root = st.top();
            st.pop();
            root = root->right;
        }
    }
    cout << endl;
}

void inorderIter(node *root)
{
    stack<node *> st;
    while (root || !st.empty())
    {
        if (root)
        {
            st.push(root);
            root = root->left;
        }
        else
        {
            root = st.top();
            st.pop();
            cout << root->data << " ";
            root = root->right;
        }
    }
    cout << endl;
}

void postOrderIterative(node* root)
{
    if (root == NULL)
        return;
    stack<node *> s1, s2;
  
    // push root to first stack
    s1.push(root);
    node* node1;
  
    // Run while first stack is not empty
    while (!s1.empty()) {
        // Pop an item from s1 and push it to s2
        node1 = s1.top();
        s1.pop();
        s2.push(node1);
  
        // Push left and right children
        // of removed item to s1
        if (node1->left)
            s1.push(node1->left);
        if (node1->right)
            s1.push(node1->right);
    }
  
    // Print all elements of second stack
    while (!s2.empty()) {
        node1 = s2.top();
        s2.pop();
        cout << node1->data << " ";
    }
}

int main()
{
    /*
            1
          /  \
         2   3
        / \   \
       4   5   6
    */
    node *root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right = new node(3);
    root->right->right = new node(6);
    preorderIter(root);
    inorderIter(root);
    postOrderIterative(root);
}