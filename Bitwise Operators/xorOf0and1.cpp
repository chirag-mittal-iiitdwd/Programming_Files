#include<bits/stdc++.h>
using namespace std;
int xorCounts0and1(int n){
    int oneCount=0;
    int numberOfEle=floor(log2(n))+1;
    while(n>0){
        oneCount++;
        n=(n&(n-1));
    }
    int zeroCount=numberOfEle-oneCount;
    cout<<numberOfEle<<" "<<zeroCount<<" "<<oneCount<<endl;
    return zeroCount^oneCount;
}
int main(){
    int n;
    cin>>n;
    cout<<xorCounts0and1(n)<<endl;
}