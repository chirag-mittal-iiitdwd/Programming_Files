#include<bits/stdc++.h>
using namespace std;
// Returns true if they have opposite signs
// else returns false
bool oppositeSign(int a,int b){
    return ((a^b)<0);
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<oppositeSign(a,b)<<endl;
}