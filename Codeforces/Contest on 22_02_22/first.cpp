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
        
        bool rK=false,bK=false,gK=false;
        string ans="YES";
        for(int i=0;i<6;i++){
            if(str[i]=='r'){
                rK=true;
            }
            else if(str[i]=='g'){
                gK=true;
            }
            else if(str[i]=='b'){
                bK=true;
            }
            else if(str[i]=='B'){
                if(!bK){
                    ans="NO";
                    break;
                }
            }
            else if(str[i]=='R'){
                if(!rK){
                    ans="NO";
                    break;
                }
            }
            else{
                if(!gK){
                    ans="NO";
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}