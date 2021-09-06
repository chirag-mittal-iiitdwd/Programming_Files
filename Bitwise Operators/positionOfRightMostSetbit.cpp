#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int position(int n){
    int ans=0;
    int m=1;
    while((n&m)==0){
        ans++;
        m=m<<1;
    }
    ans++;
    return ans;
}

int positionRightMost(int n){
    return log2(n&-n)+1;
}

int main(){
    int n;
    cin>>n;
    cout<<position(n);
    return 0;
}
