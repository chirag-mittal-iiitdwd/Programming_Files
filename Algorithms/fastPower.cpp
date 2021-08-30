#include<iostream>
using namespace std;

long long int fastPower(long long int a,long long int b,int n){
    long long int res=1;
    while(b>0){
        if((b&1)!=0){
            // We know (a*b)%n = ((a%n )* (b%n))%n
            // Instead of res*a
            res=((res)*(a%n))%n;
        }
        a=((a%n)*(a%n))%n;
        b=b>>1;
    }
    return res;
}

int main(){
    cout<<fastPower(345633513,5,1000000007);
}