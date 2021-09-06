#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int position(int n){
    int nd=n;
    int ans=0;
    while(n>0){
        ans++;
        if(ans>1){
            break;
        }
        n=(n&(n-1));
    }
    if(ans==1){
        return log2(nd&-nd)+1;
    }
    else{
        return -1;
    }
}
int main(){
    int n;
    cin>>n;
    cout<<position(n)<<endl;
    return 0;
}