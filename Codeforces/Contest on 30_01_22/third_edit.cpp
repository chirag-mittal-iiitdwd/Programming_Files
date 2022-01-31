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
        int a,b;
        cin>>a>>b;

        int ans=b-a;

        for(int i=0;i<b-a;i++){
            if(((a+i)|b)==b){
                ans=min(ans,i+1);
                break;
            }
        }

        for(int i=0;i<b;i++){
            if((a|(b+i))==(b+i)){
                ans=min(ans,i+1);
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}