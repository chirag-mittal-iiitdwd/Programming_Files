#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int calInversions(string str,int m){
    int oneCnt=0;
    int ans=0;
    for(int i=0;i<m;i++){
        if(str[i]=='1'){
            oneCnt++;
        }
        else{
            ans+=oneCnt;
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<string>v;
        map<string,int,greater<int>()>mp; // string,inversion
        map<int,string>mp1; // inversions,strings
        for(int i=0;i<n;i++){
            string x;
            cin>>x;
            v.push_back(x);
            int inv=calInversions(x,m);
            mp1[inv]=x;
        }
        for(auto it:mp1){
            mp[it.second]=it.first;
        }

        for(auto it:mp){
            
        }
    }
    return 0;
}