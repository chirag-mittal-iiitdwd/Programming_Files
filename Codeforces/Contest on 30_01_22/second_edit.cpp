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

int highestPowerof2(int n){
    int res = 0;
    for (int i=n; i>=1; i--){
        if ((i & (i-1)) == 0){
            res = i;
            break;
        }
    }
    return res;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int idx=highestPowerof2(n-1);

        for(int i=idx-1;i>=0;i--){
            cout<<i<<" ";
        }
        for(int i=idx;i<n;i++){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}