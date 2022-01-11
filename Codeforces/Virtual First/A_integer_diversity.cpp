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
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            if(arr[i]>=0){
                mp[arr[i]]++;
            }
            else{
                mp[-arr[i]]++;
            }
        }

        int ans=0;
        for(auto &it:mp){
            if(it.first==0){
                ans+=1;
            }
            else if(it.second==1){
                ans+=1;
            }
            else{
                ans+=2;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}