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
    int n;
    cin>>n;
    int ans=0;
    while(n--){
        string str;
        cin>>str;
        if(str[0]=='-' || str[1]=='-'){
            ans--;
        }
        else if(str[0]=='+'||str[1]=='+'){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}