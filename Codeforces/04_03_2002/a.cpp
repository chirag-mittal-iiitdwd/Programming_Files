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
        int n,s;
        cin>>n>>s;

        int zeroSq=n+1*(n-1);
        int ans=0;
        if((n==1 && s==1)){
            cout<<1<<endl;
        }
        else if(s==0){
            cout<<0<<endl;
        }
        else{
            for(int i=0;i<=(n+1);i++){
                int sum=zeroSq-(i*(n-1))+(i*(n*n));
                if(sum<=s){
                    ans=i;
                }
                else{
                    break;
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}