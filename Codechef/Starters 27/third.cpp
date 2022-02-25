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
        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }

        for(int i=1;i<n;i++){
            if((i!=(n-1)) && __gcd(v[i-1],v[i])==1){
                v[i]=(v[i-1]*v[i+1]);
            }
            else{
                if(__gcd(v[i-1],v[i])==1){
                    v[i]=v[i-1];
                }
            }
        }

        for(auto&it:v){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    return 0;
}