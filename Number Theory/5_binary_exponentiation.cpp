#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int power(int a,int n){
    int res=1;
    while(n){
        if(n%2){
            res*=a;
            n--;
        }
        else{
            a*=a;
            n/=2;
        }
    }
    return res;
}

int powerWithMod(int a,int n,int p){
    int res=1;
    while(n){
        if(n%2){
            res=(res*a)%p;
            n--;
        }
        else{
            a=(a*a)%p;
            n/=2;
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    return 0;
}