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
        int n;
        cin>>n;
        vector<int>arr(n);
        set<int>s;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            s.insert(arr[i]);
        }

        int maxi=INT_MIN;
        for(auto&it:arr){
            maxi=max(it,maxi);
        }
        if(arr[0]==maxi && s.size()!=1){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}