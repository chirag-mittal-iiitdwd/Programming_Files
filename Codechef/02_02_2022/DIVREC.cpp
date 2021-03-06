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
        int x,a,b;
        cin>>x>>a>>b;

        int n=x*b;
        if(n%a==0){
            n/=a;
        }
        else{
            cout<<-1<<"\n";
            continue;
        }

        if(n>x){
            cout<<-1<<"\n";
            continue;
        }

        int sum=0;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                sum+=i;
                if(i*i!=n){
                    sum+=n/i;
                }
            }
        }

        if(sum==x){
            cout<<n<<"\n";
        }
        else{
            cout<<-1<<endl;
        }
    }
    return 0;
}