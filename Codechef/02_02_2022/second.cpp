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

// bool isWin()

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int a,b,c,p,q,r;
        cin>>a>>b>>c>>p>>q>>r;

        int got=a+b+c;
        int total=p+q+r;
        int half=(total/2);
        if(half< got){
            cout<<"YES\n";
        }
        else{
            int newA=p;
            int newB=q;
            int newC=r;

            if((half<(newA+b+c)) || (half<(newB+a+c)) || (half<(newC+a+b))){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }
    }
    return 0;
}