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

bool isRequired(vector<int>v,int n){
    vector<int>temp(n-1);
    for(int i=1;i<n;i++){
        int absDiff=abs(v[i]-v[i-1]);
        temp[i-1]=absDiff;
    }

    int ans=0;
    for(int i=0;i<n-1;i++){
        ans^=temp[i];
    }

    if(ans!=0){
        return false;
    }
    return true;
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
        
        if(n&1){
            for(int i=1;i<=n;i++){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        else{
            
        }
    }
    return 0;
}