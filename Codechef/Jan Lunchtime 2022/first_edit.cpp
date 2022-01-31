#include<bits/stdc++.h>
/*
    Soring
    Stack
    Queue
    Dynamic Programming
    Backtracking
    Linked List
    Sliding Window
    Tree
    Two Pointer
    Binary Search
    Maths
    Graph
    Greedy
    Heaps
    Hashing
    
*/
using namespace std;
#define int long long int
#define mod 1000000007
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;

        if(n==1 && k==1){
            cout<<1<<endl;
        }
        else if(n!=1 && k==1){
            cout<<-1<<endl;
        }
        else{
            int arr[n];
            for(int i=0;i<n;i++){
                arr[i]=i+1;
            }

            swap(arr[k-1],arr[n-1]);
            for(int i=0;i<n;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}