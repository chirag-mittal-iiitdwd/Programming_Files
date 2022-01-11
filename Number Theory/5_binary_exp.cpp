#include<bits/stdc++.h>
using namespace std;

int binary_exp(int a,int b){
    int ans=1;
    while(b){
        if(b&1){
            b--;
            ans=ans*a;
        }
        else{
            b/=2;
            a=a*a;
        }
    }
    return ans;
}

int main(){
    int a,b;
    cin>>a>>b;
    cout<<binary_exp(a,b)<<endl;
}