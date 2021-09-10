#include<bits/stdc++.h>
using namespace std;

int toggleKthBit(int n,int k){
    int m=1<<(k-1);
    return (n^m);
}

int main(){
    int n,k;
    cin>>n>>k;
    cout<<toggleKthBit(n,k);
}