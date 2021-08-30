/*
    Time Complexity : T(n) = T(n-1) + T(n-2)
    space complexity : O(N) ---> Including call stack
*/
#include<bits/stdc++.h>
using namespace std;
int fibonacciSeries(int n){
    if(n==1 || n==0){
        return n;
    }
    return fibonacciSeries(n-1)+fibonacciSeries(n-2);
}
int main(){
    int n=10;
    for(int i=0;i<n;i++){
        cout<<fibonacciSeries(i)<<" ";
    }
    cout<<endl;
    return 0;
}