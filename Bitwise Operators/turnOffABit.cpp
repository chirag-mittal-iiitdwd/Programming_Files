#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int turnOffK(int n,int k){
    if(k<=0){
        return n;
    }
    return (n & ~(1<<(k-1)));
}

int main(){
    int n,k;
    cin>>n>>k;
    cout<<turnOffK(n,k)<<endl;
    return 0;
}