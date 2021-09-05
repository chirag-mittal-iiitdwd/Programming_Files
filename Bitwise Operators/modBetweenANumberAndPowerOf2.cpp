#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int getModulo(int n,int d){
    return (n&(d-1));
}
int main(){
    int n,d;
    cin>>n>>d;
    cout<<getModulo(n,d)<<endl;
    return 0;
}