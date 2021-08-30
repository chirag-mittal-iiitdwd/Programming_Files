/*
    
*/
#include<bits/stdc++.h>
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n=10,k=4,l;
    float x=(float)n/(float)k;
        if(x==n/k){
            l=x;
        }
        else{
            l=(n/k)+1;
        }
        cout<<l;
    return 0;
}