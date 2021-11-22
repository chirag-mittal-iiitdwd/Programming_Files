#include<bits/stdc++.h>
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
        map<int,int>mp;
        int smaller=INT_MAX;
        int gratest=INT_MIN;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            smaller=min(smaller,x);
            gratest=max(gratest,x);
            mp[x]++;
        }
        if(smaller==gratest){
            cout<<0<<endl;
        }
        else{
            int i=0;
            int cnt=0;
            int first=smaller;
            int first_sec=mp[smaller];
            for(auto it:mp){
                if(i==0 && it.first!=gratest){
                    continue;
                }
                else if(it.first!=gratest){
                    cnt+=(it.first-first);
                    it.second+=first_sec;
                    first=it.first;
                    first_sec=it.second;
                }
                i++;
            }
            if(smaller==first){
                cout<<gratest-smaller<<endl;
            }
            else{
                cnt+=(gratest-first);
                cout<<cnt<<endl;
            }
        }
    }
    return 0;
}