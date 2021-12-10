#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=2;
    while(pow(2,n/8)<n){
        n+=1;
    }
    cout<<"Maximum value for n where it beats insertion sort : "<<n-1<<endl;
}