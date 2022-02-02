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

bool isPowerof2N_1(int n){
    if((n&n-1)==0){
        return true;
    }
    return false;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        int bits=log2(x)+1;
        int first=0,sec=0,third=0;
        if(isPowerof2N_1(x+1)){
            first=0;
            sec=x;
            third=(2*(x+1))-1;
        }
        else{
            for(int i=0;i<bits;i++){
                bool isSet=(x&(1<<i));
                if(isSet){
                    first+=pow(2,i);
                    sec+=pow(2,i);
                }
                else{
                    first+=pow(2,i);
                }
            }
        }
        cout<<first<<" "<<sec<<" "<<third<<endl;
        // int z=((first)|(sec))&((first)|(third))&((sec)|(third));
        // cout<<z<<endl;
    }
    return 0;
}