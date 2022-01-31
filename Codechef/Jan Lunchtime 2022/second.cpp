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
// #define int long long int
// #define mod 1000000007
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string str;
        cin>>str;
        int ans=0;

        for(int i=0;i<n;i++){
            int req='9'-str[i]+1;
            if(req==10){
                ans++;
            }
            else{
                if(k>=req){
                    k-=req;
                    ans++;
                }
                else{
                    break;
                }
            }
        }
        cout<<"ans : "<<ans<<endl;
    }
    return 0;
}