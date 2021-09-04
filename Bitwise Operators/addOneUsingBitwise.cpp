#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int addOne(int x){
    int m=1;
    while(x&m){
        x=x^m;
        m<<=1;
    }
    x=x^m;
    return x;
}
int main(){
    int n;
    cin>>n;
    cout<<addOne(n);
    return 0;
}