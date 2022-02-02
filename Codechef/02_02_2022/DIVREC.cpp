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
        int x,a,b;
        cin>>x>>a>>b;

        if(x==1 && a==1 && b==1){
            cout<<1<<endl;
        }
        else if(b==1){
            cout<<-1<<endl;
        }
        else{
            cout<<b<<endl;
        }
    }
    return 0;
}