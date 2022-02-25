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
        int n,x,y;
        cin>>n>>x>>y;

        int minSmoke=INT_MAX;
        for(int i=0;i<=n;i++){
            double bus=i;
            double car=n-i;
            int smoke=0;
            smoke+=((ceil(bus/100.0))*x);
            smoke+=((ceil(car/4.0))*y);
            minSmoke=min(smoke,minSmoke);
        }
        cout<<minSmoke<<endl;
    }
    return 0;
}