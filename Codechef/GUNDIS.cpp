/*
    
*/
#include<bits/stdc++.h>
#define ll long long int
#define maxval (int)(1e9+7)
using namespace std;


class Solution{
    public:
    ll maxIntimidations(ll arr[],ll n){
        ll prod=1;
        ll curr=1;
        for(ll i=0;i<n-1;i++){
            ll curentIDX=i;
            ll nextIDX=i+1;
            // cout<<"arr[curentIDX] : "<<arr[curentIDX]<<" "<<"arr[nextIDX]"<<arr[nextIDX]<<endl;
            if(arr[curentIDX]==arr[nextIDX]){
                if(curr!=1){
                    // cout<<"CURR :"<<curr<<endl;
                    prod*=curr;
                    curr=1;
                }
            }
            else if(curr==3){
                prod*=curr;
                curr=1;
            }
            else{
                curr++;
            }
        }
        // cout<<"CURR :"<<curr<<endl;
        prod*=curr;
        prod=prod%maxval;
        return prod;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll arr[n];
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution obj;
        cout<<obj.maxIntimidations(arr,n)<<"\n";
    }
    return 0;
}