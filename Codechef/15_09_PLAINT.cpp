// https://www.codechef.com/SEPT21C/problems/PALINT
// https://www.youtube.com/watch?v=LlHqfk2XX_M&t=757s
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        map<int,int>mp;
        int mx_freq=0;
        for(int i=0;i<n;i++){
            int num;
            cin>>num;
            mp[num]++;
            mx_freq=max(mx_freq,mp[num]);
        }
        int operations=0;
        for(auto it:mp){
            int cnt=it.second;
            if(x!=0){
                // The numbers which can be converted to current key
                cnt+=mp[it.first^x];
            }
            int reqOperations=mp[it.first^x];

            if(cnt>mx_freq){
                mx_freq=cnt;
                operations=reqOperations;
            }
            else if(cnt==mx_freq){
                operations=min(operations,reqOperations);
            }
        }   
        cout<<mx_freq<<" "<<operations<<endl;
    }
}