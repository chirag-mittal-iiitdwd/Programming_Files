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
int t,hm,hc,dm,dc,k,w,a;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>t;
    while(t--){
        cin>>hc>>dc>>hm>>dm>>k>>w>>a;
        bool flag=false;
        for(int i=0;i<=k;i++){
            int newHealth=(hc+(i*a));
            int newAttack=(dc+((k-i)*w));
            int cAttacks=(hm+newAttack-1)/newAttack;
            int mAttacks=(newHealth+dm-1)/dm;
            if(cAttacks<=mAttacks){
                cout<<"YES"<<endl;
                flag=true;
                break;
            }
        }
        if(!flag){
            cout<<"NO"<<endl;
        }
    }
    return 0;
}