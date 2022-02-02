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
        if((n%7)==0){
            cout<<n<<endl;
        }
        else{
            // int rem=n%7;
            // int last=n%10;
            // int n_l=rem+last;
            // if(n_l<10){
            //     n+=rem;
            //     cout<<n<<endl;
            // }
            // else{
            //     n-=rem;
            //     cout<<n<<endl;
            // }
            int x=n/7;
            int last=n%10;
            int n_last=n-last;
            int cur=x*7;
            int next=(x+1)*7;
            if(cur>n_last && cur<(n_last+10)){
                cout<<cur<<endl;
            }
            else{
                cout<<next<<endl;
            }
        }
    }
    return 0;
}