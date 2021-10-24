#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        int grater=n;
        int lower=0;
        int boast=0;
        for(auto it:mp){
            lower+=it.second;
            grater-=it.second;
            if(lower>grater){
                boast+=it.second;
            }
        }
        cout<<boast<<endl;
    }
    return 0;
}