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

// bool isAntiPal(vector<int>&v,int&n){
//     int i=2;
//     for(;i<n;i++){
//         if(v[i]==(v[i-1]+v[i-2])){
//             break;
//         }
//     }
//     if(i==n){
//         return true;
//     }
//     return false;
// }

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n==3){
            cout<<3<<" "<<2<<" "<<1<<endl;
            cout<<1<<" "<<3<<" "<<2<<endl;
            cout<<3<<" "<<1<<" "<<2<<endl;
            continue;
        }
        vector<int>v(n);
        int x=1;
        for(int i=n-1;i>=0;i--){
            v[i]=x;
            x++;
        }
        vector<vector<int>>ans;
        ans.push_back(v);
        for(int i=0;i<n-2;i++){
            v=ans[0];
            swap(v[n-i-1],v[n-i-2]);
            ans.push_back(v);
        }
        v=ans[1];
        swap(v[1],v[2]);
        ans.push_back(v);

        for(auto&it:ans){
            for(auto&i:it){
                cout<<i<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}