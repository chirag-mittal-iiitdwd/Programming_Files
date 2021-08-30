#include "bits/stdc++.h" // 27.11
using namespace std;
/*

    (ans)1
        / \
  (ans)2   3
      / \ / \
(ans)4  5 6  7

*/

/* 
-----> Algorithm
1. Travesing the tree level wise
2. Storing the leftmost most node of every level
*/

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

// Since we have inserted each element only once into our queue 
// so that is why we have trivesed the whole tree
// Time complexity = O(n) n=number of nodes
void leftView(node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            node *curr = q.front();
            q.pop();
            if (i == 0)
            {
                cout << curr->data << " ";
            }
            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }
    }
    cout << endl;
}
int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    leftView(root);
}