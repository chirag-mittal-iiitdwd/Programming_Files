#include<bits/stdc++.h>
using namespace std;

// class node{
//     publicw:
//     int data;
//     node*next;
//     node(int val){
//         data=val;
//         next=NULL;
//     }
// };

// void insertAtHead(node*&head,int val){
//     node*n=new node(val);
//     n->next=head;
//     head=n;
// }

// void display(node*head){
//     node*temp=head;
//     while(temp!=NULL){
//         cout<<temp->data<<" ";
//         temp=temp->next;
//     }
//     cout<<endl;
// }

// class Solution{
//     void insertAtHead(node*&head,int data){
//         node*n=new node(data);
//         n->next=head;
//         head=n;
//     }
//     void insertAtTail(node*&head,int data){
//         if(head==NULL){
//             insertAtHead(head,data);
//             return;
//         }
//         node*temp=head;
//         node*n=new node(data);
//         while(temp->next!=NULL){
//             temp=temp->next;
//         }
//         temp->next=n;
//     }
//     void makeEqualLength(string&str1,string&str2){
//         int n1=str1.length();
//         int n2=str2.length();
//         int diff=n1-n2;
//         if(diff==0){
//             return;
//         }
//         else if(n1>n2){
//             for(int i=0;i<diff;i++){
//                 str2+='0';
//             }
//         }
//         else{
//             diff*=-1;
//             for(int i=0;i<diff;i++){
//                 str1+='0';
//             }
//         }
//     }
//     string addTwoStrings(string&str1,string&str2){
//         int carry=0;
//         string ans{""};
//         makeEqualLength(str1,str2);
//         int n=str1.length();
//         for(int i=0;i<n;i++){
//             int first=str1[i]-'0';
//             int second=str2[i]-'0';
//             int sum=first+second+carry;
//             int rem=sum%10;
//             carry=sum/10;
//             ans+=to_string(rem);
//         }
//         if(carry!=0){
//             ans+=to_string(carry);
//         }
//         return ans;
//     }
//     public:
//     node* addTwoNumbers(node*l1,node*l2){
//         string num1{""},num2{""};
//         node*temp1=l1;
//         node*temp2=l2;
//         while(temp1!=NULL && temp2!=NULL){
//             num1+=to_string(temp1->data);
//             num2+=to_string(temp2->data);
//             temp1=temp1->next;
//             temp2=temp2->next;
//         }
//         while(temp2!=NULL){
//             num2+=to_string(temp2->data);
//             temp2=temp2->next;
//         }
//         while(temp1!=NULL){
//             num1+=to_string(temp1->data);
//             temp1=temp1->next;
//         }
//         string ans=addTwoStrings(num1,num2);
//         int n=ans.length();
//         node*head=NULL;
//         for(int i=0;i<n;i++){
//             insertAtTail(head,ans[i]-'0');
//         }
//         return head;
//     }
// };

// int main(){
//     node*head1=NULL;
//     node*head2=NULL;
//     insertAtHead(head1,9);
//     insertAtHead(head1,9);
//     insertAtHead(head1,9);
//     insertAtHead(head1,9);
//     insertAtHead(head1,9);
//     insertAtHead(head1,9);
//     insertAtHead(head1,9);

//     insertAtHead(head2,9);
//     insertAtHead(head2,9);
//     insertAtHead(head2,9);
//     insertAtHead(head2,9);

//     display(head1);
//     display(head2);

//     Solution obj;
//     node*head=obj.addTwoNumbers(head1,head2);
//     display(head);
// }

// 2nd try

class ListNode{
    public:
    int val;
    ListNode*next;
    ListNode(int data){
        val=data;
        next=NULL;
    }
};

class Solution {
    ListNode*helper(ListNode*&temp1,ListNode*&temp2,int&carry,ListNode*&head,ListNode*&iter){
        if(temp1==NULL && temp2==NULL){
            return head->next;
        }
        int val=carry;
        if(temp1!=NULL){
            val+=temp1->val;
        }
        if(temp2!=NULL){
            val+=temp2->val;
        }
        if(temp1!=NULL){
            val+=temp1->val;
        }
        if(temp2!=NULL){
            val+=temp2->val;
        }
        carry=val/10;
        val=val%10;
        iter->next=new ListNode(val);
        if(temp1!=NULL && temp2!=NULL){
            return helper(temp1->next,temp2->next,carry,head,iter->next);
        }
        else if(temp1!=NULL){
            return helper(temp1->next,temp2,carry,head,iter->next);
        }
        else{
            return helper(temp1,temp2->next,carry,head,iter->next);
        }
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*temp1=l1;
        ListNode*temp2=l2;
        ListNode*head=new ListNode(-1);
        ListNode*iter=head;
        int carry=0;
        return helper(temp1,temp2,carry,head,iter);
    }
};