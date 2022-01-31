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
        string str;
        cin>>str;

        int one=0,zero=0;
        for(auto&it:str){
            if(it=='1'){
                one++;
            }
            else{
                zero++;
            }
        }
        if(one==1 && zero==1){
            cout<<"YES"<<endl;
        }
        else if(one==1 && zero==0){
            cout<<"YES"<<endl;
        }
        else if(one==0 && zero==1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}