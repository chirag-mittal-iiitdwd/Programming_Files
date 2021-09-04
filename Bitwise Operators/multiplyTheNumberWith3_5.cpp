#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int multiplyWith3_5(int x){
    return (x<<1)+x+(x/2);
}
int main(){
    int n;
    cin>>n;
    cout<<multiplyWith3_5(n);
    return 0;
}