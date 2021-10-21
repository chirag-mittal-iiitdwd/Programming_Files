/*
    
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define target int((1e7)+2)
int arr[target];
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    primeSieve();
    while(t--){
        ll x,y;
        cin>>x>>y;
        // if((y-x)>)
        ll steps=0;
        ll tempx=x;
        while(tempx!=y){
            cout<<"tempx : "<<tempx<<endl;
            if(arr[tempx+2]==0){
                cout<<"exeif"<<endl;
                tempx+=2;
                steps++;
            }
            else{
                cout<<"exeelse"<<endl;
                tempx+=1;
                steps++;
            }
        }
        // cout<<"tempx"<<tempx<<endl;
        // if(tempx!=y && prime[tempx]!=0){
        //     cout<<"if"<<endl;
        //     steps++;
        // }
        cout<<steps<<endl;
    }
    return 0;
}