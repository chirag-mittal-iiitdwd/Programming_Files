/*
    
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int sm=INT_MAX;
        int gr=INT_MIN;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            sm=min(sm,x);
            gr=max(gr,x);
            mp[x]++;
        }
        if(sm==gr){
            cout<<0<<endl;
        }
        else{
            int i=0;
            int cnt=0;
            for(auto it:mp){
                if(i!=0){
                    cnt+=(it.first-sm);
                    it.second+=mp[sm];
                    sm=it.first;
                }
                i++;
            }
            cout<<cnt<<endl;
        }
    }
    return 0;
}