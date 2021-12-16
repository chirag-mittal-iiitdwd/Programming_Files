#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node*next;
    Node(int data){
        val=data;
        next=NULL;
    }
};

void insertAtHead(Node*&head,int data){
    Node*n=new Node(data);
    n->next=head;
    head=n;
}
void display(Node*head){
        Node*temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

class Solution {
    void insertAtHead(Node*&head,int data){
        Node*n= new Node(data);
        n->next=head;
        head=n;
    }
public:
    Node* mergeKLists(vector<Node*> lists) {
        int n=lists.size();
        Node*newHead=NULL;
        vector<int>arr;
        for(int i=0;i<n;i++){
            while(lists[i]){
                arr.push_back(lists[i]->val);
                lists[i]=lists[i]->next;
            }
        }
        sort(arr.begin(),arr.end());
        n=arr.size();
        for(int i=n-1;i>=0;i--){
            insertAtHead(newHead,arr[i]);
        }
        return newHead;
    }
};

// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         int k;
//         cin>>k;
//         vector<Node*>arr;
//         for(int i=0;i<k;i++){
//             int n;
//             cin>>n;
//             Node*head=NULL;
//             vector<int>arr2(n);
//             for(int i=0;i<n;i++){
//                 cin>>arr2[i];
//             }
//             for(int i=n-1;i>=0;i--){
//                 insertAtHead(head,arr2[i]);
//             }
//             arr.push_back()
//         }
//     }
// }