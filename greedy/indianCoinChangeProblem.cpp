/*
    We have given an array of denominations and a value X. We have to find
    the minimum number of coins required to make value X
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={2000,500,200,100,50,20,10,5,2,1};
    int n=2000;
    int ans=0;
    for(int i=0;i<10;i++){
        ans+=(n/arr[i]);
        n-=(n/arr[i])*(arr[i]);
    }
    cout<<ans<<endl;
}