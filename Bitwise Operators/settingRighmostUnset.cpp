#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int rightMostSetBit(int n){
    return log2(n&-n)+1;
}

int setRightUnsetBit(int n){
    if(n==0){
        return 1;
    }
    else if((n&(n+1))==0){
        return n;
    }
    else{
        int pos=rightMostSetBit(~n);
        return ((1<<(pos-1))|n);
    }
}

int main(){
    return 0;
}