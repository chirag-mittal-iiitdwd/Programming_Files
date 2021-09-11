#include<bits/stdc++.h>
using namespace std;
unsigned int toggleEveryBitExceptKth(unsigned int n,unsigned int k){
    return ~(n^(1<<k));
}
int main(){
    unsigned int n,k;
    cin>>n>>k;
    cout<<toggleEveryBitExceptKth(n,k)<<endl;
}


// ~ represent in bit then invert bits --> bitwise not
// ! not operator