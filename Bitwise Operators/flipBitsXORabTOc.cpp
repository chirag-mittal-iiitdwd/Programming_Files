#include<bits/stdc++.h>
using namespace std;

int numberOfBits(int n){
    int count=0;
    while(n>0){
        count++;
        n=(n&(n-1));
    }
    return count;
}
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    cout<<numberOfBits(a^b^c)<<endl;
}