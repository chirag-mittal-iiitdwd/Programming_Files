#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll getMaxPrimeFactor(ll n) {
   ll i, max = -1;
   while(n % 2 == 0) {
      max = 2;
      n = n/2; //reduce n by dividing this by 2
   }
   for(i = 3; i <= sqrt(n); i=i+2){ //i will increase by 2, to get
      while(n % i == 0) {
         max = i;
         n = n/i;
      }
   }
   if(n > 2) {
      max = n;
   }
   return max;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        k=k%n;
        if(k!=0 && k!=1){
            k=getMaxPrimeFactor(k);
        }
        // cout<<"K : "<<k<<endl;
        ll hcf=__gcd(k,n);
        if(k==0){
            cout<<1<<"\n";
        }
        else if(hcf==1){
            cout<<n<<"\n";
        }
        else{
            cout<<n/k<<"\n";
        }
    }
    return 0;
}