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
        string str;
        cin>>str;

        int n=str.length();
        int one=0,zero=0;
        for(int i=0;i<n;i++){
            if(str[i]=='0'){
                zero++;
            }
            else{
                one++;
            }
        }
        if(one!=zero){
            cout<<min(one,zero)<<endl;
        }
        else{
            cout<<one-1<<endl;
        }
    }
    return 0;
}