#include<iostream>
using namespace std;
bool function(long long int n,long long int x,long long int k){
    long long int currentPos=0;
    bool ans=false;
    for(long long int i=0;i<k;i++){
        for(long long int j=0;j<=n+1;j+=k){
            if(currentPos==x){
                ans=true;
                break;
            }
            currentPos+=k;
        }
        long long int duplicateCurrent=currentPos;
        for(long long int j=duplicateCurrent;j>=0;j-=k){
            if(currentPos==x){
                ans=true;
                break;
            }
            currentPos-=k;
        }
    }
    return ans;
}

int main(){
    long long int t;
    cin>>t;
    while(t--){
        long long int n=0;
        long long int x=0;
        long long int k=0;
        cin>>n>>x>>k;
        if(function(n,x,k)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}