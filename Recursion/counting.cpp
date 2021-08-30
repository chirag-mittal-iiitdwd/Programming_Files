/*
    If the recursive call is the last statement in the function than
    it is called tail recursion.

    If the recursive call is the first statement in the function than
    it is called head recursion.

    reverseCounting and forwardcounting functions below have
    time Complexity : O(N) and Space complexity : O(N)
    Space Complexity ---> Including call stack
    this is because it consumes N space in the stack.
*/
#include<bits/stdc++.h>
using namespace std;

void reverseCounting(int n){
    if(n==0){
        return;
    }
    cout<<n<<" ";
    reverseCounting(n-1);
}

void forwardCounting(int n){
    if(n==0){
        return;
    }
    forwardCounting(n-1);
    cout<<n<<" ";
}

int main(){
    int n=5;
    reverseCounting(n);
    cout<<endl;
    forwardCounting(n);
    cout<<endl;
    return 0;
}