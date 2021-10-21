#include<bits/stdc++.h>
#define ll long long int
#define target int(1e7)
using namespace std;
// We can only jump from x to x+2 if x+2 is prime so if x and x+1 are prime it does not matter
vector<ll>arr(target+2,0);
void primeSieve(){
    for(ll i=2;i<=target;i++){
        if(arr[i]==0){
            for(ll j=i*i;j<=target;j+=i){
                arr[j]=1;
            }
        }
    }
}

int main(){
    ll t;
    cin>>t;
    primeSieve();
    while(t--){
        ll x,y;
        cin>>x>>y;
        ll primeCount=0;
        for(ll i=x+2;i<=y;i++){
            if(arr[i]==0){
                primeCount++;
            }
        }


        // cout<<"Prime Count : "<<primeCount<<endl;

        // ll distanceToBeCovered=y-x+1;
        // cout<<"Distance To Be Covered : "<<distanceToBeCovered<<endl;
        // ll coveredByPrime=2*primeCount;
        // ll distanceLeft=distanceToBeCovered-coveredByPrime;
        // cout<<"Left Distance : "<<distanceLeft<<endl;
        // cout<<primeCount+distanceLeft<<endl;

        cout<<(y-x-primeCount)<<endl;
    }
}