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

bool isfitForOr(int a,int b){
    int x=log2(a)+1;

    for(int i=0;i<x;i++){
        bool aa= a&(1<<i);
        if(aa){
            bool bb=b&(1<<i);
            if(!bb){
                return false;
            }
        }
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
        int a,b;
        cin>>a>>b;

        int cnt=0;
        while(!isfitForOr(a,b)){
            a++;
            cnt++;
        }
        cout<<cnt+1<<endl;
    }
    return 0;
}