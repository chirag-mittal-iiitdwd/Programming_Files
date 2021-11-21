/*
    
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
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

        ll oneCnt=0;
        ll twoCnt=0;
        for(ll i=0;i<n;i++){
            ll rem=arr[i]%3;
            if(rem==1){
                oneCnt++;
            }
            else if(rem==2){
                twoCnt++;
            }
        }
        if(oneCnt==twoCnt){
            cout<<oneCnt<<endl;
        }
        else if(oneCnt%2==0 && twoCnt==0){
            if(twoCnt%3==0){
                cout<<(twoCnt/2)+1<<endl;
            }
        }
        else if(twoCnt%2==0 && oneCnt==0){
            if(oneCnt%3==0){
                cout<<(oneCnt/2)+1<<endl;
            }
        }
        else{
            cout<<-1<<endl;
        }
    }
    return 0;
}