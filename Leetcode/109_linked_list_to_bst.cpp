#include<bits/stdc++.h>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 

// class Solution {
// public:
//     TreeNode* sortedListToBST(ListNode* head) {
//         if(head==NULL){
//             return NULL;
//         }
//         if(head->next==NULL){
//             return new TreeNode(head->val);
//         }

//         ListNode*slow=head;
//         ListNode*fast=head;
//         while(fast!=NULL && fast->next!=NULL){
//             fast=fast->next->next;
//             slow=slow->next;
//         }

//         ListNode*temp=slow;
//         slow=slow->next;
//         temp->next=NULL;
//         TreeNode*root=new TreeNode(slow->val);
//         root->left=sortedListToBST(head);
//         root->right=sortedListToBST(slow);
//         return root;
//     }
// };


class Solution {
    TreeNode*helper(ListNode*head,ListNode*tail){
        if(head==tail){
            return NULL;
        }
        if(head->next==tail){
            return new TreeNode(head->val);
        }

        ListNode*fast=head;
        ListNode*slow=head;
        while(fast!=tail && fast->next!=tail){
            fast=fast->next->next;
            slow=slow->next;
        }

        TreeNode*root=new TreeNode(slow->val);
        root->left=helper(head,slow);
        root->right=helper(slow->next,tail);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return helper(head,NULL);
    }
};