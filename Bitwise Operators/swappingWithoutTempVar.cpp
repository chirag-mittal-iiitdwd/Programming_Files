#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void swapw(int &a,int &b){
    a=a^b;
    b=b^a;
    a=a^b;
}
int main(){
    int n,a;
    cin>>n>>a;
    swapw(a,n);
    cout<<n<<" "<<a<<endl;
    return 0;
}