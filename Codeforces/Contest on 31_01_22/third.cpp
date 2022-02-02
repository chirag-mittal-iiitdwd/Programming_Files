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

bool winOrNot(int hc,int dc,int hm,int dm){
    int f=(hm/dc);
    int s=(hc/dm);

    return f<=s;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int hc,dc;
        cin>>hc>>dc;
        int hm,dm;
        cin>>hm>>dm;
        int k,w,a;
        cin>>k>>w>>a;

        if(k==0){
            if(winOrNot(hc,dc,hm,dm)){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }
        else{
            bool ans=false;
            int attack=0;
            int armor=k;
            while(armor>=0){
                int newHealth=hc+(a*armor);
                int newattack=dc+(w*attack);
                ans=winOrNot(newHealth,newattack,hm,dm);
                if(ans){
                    break;
                }
                armor--;
                attack++;
            }
            if(ans){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }
    }
    return 0;
}