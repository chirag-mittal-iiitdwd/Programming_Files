#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int flippedBits(int a,int b){
    int n=a^b;
    int ans=0;
    while(n>0){
        ans++;
        n=(n&(n-1));
    }
    return ans;
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<flippedBits(a,b)<<endl;
    return 0;
}