#include<bits/stdc++.h>
using namespace std;

void checkAltPattern(int n){
    int numberOfBits=log2(n)+1;
    int m=1;
    int currentBit=n&m;
    string ans="Yes";
    for(int i=1;i<numberOfBits;i++){
        m=m<<1;
        if(currentBit==(!(currentBit&m))){
            ans="No";
            break;
        }
    }
    cout<<ans<<endl;
}

int main(){
    int n;
    cin>>n;
    checkAltPattern(n);
}