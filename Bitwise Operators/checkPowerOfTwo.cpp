#include<bits/stdc++.h>
using namespace std;
bool checkPowerOfTwo(int n){
    if(n==0){
        return false;
    }
    int ans=0;
    while(n>0){
        ans++;
        n=(n&(n-1));
    }
    if(ans==1){
        return true;
    }
    else{
        return false;
    }
}

bool ispoweroftwo(int n){
    if(n==0){
        return 0;
    }
    return (ceil(log2(n))==floor(log2(n)));
}

int main(){
    int n;
    cin>>n;
    cout<<checkPowerOfTwo(n)<<endl;
}