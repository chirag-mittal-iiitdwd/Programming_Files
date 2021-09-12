#include<bits/stdc++.h>
using namespace std;

void toggleTheLastMBits(int &n,int m){
    int x=1;
    while(m>0){
        n=(n^x);
        x=x<<1;
        m--;
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    toggleTheLastMBits(n,m);
    cout<<n<<endl;
}