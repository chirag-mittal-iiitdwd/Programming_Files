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
        int n,x;
        cin>>n>>x;
        int maxi=x;
        int total=x;
        for(int i=0;i<n;i++){
            int z;
            cin>>z;
            total+=z;
            maxi=max(maxi,total);
        }

        cout<<maxi<<endl;
    }
    return 0;
}