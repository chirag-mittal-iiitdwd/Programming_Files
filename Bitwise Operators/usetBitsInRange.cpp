#include<bits/stdc++.h>
using namespace std;
int toggleBitsInRange(int n,int l,int r){
    int x=log2(n);
    int power=pow(2,x);
    int m=(power>>l);
    for(int i=l;i<=r;i++){
        n=n^m;
        m=m>>1;
    }
    return n;
}
int unsettoggleBitsInRange(int n,int l,int r){
    int x=log2(n);
    int power=pow(2,x);
    cout<<power<<endl;
    int m=(power>>l);
    cout<<m<<endl;
    for(int i=l;i<=r;i++){
        n=n^(~m);
        m=m>>1;
    }
    return n;
}

int main(){
    int n,l,r;
    cin>>n>>l>>r;
    cout<<toggleBitsInRange(n,l,r)<<endl;
}