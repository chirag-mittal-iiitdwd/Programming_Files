/*
    
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
    int n;
    cin>>n;
    int i;
    vector<int>a(n);
    map<int,int>fre;
    for(int i=0;i<n;i++){
        cin>>a[i];
        fre[a[i]]++;
    }
    int maxi=*max_element(a.begin(),a.end());
    for(auto it:fre){
        if(it.second>=3){
            cout<<"-1"<<endl;
            return;
        }
    }

    if(fre[maxi]==2){
        cout<<"-1"<<endl;
        return;
    }
    vector<int>increase;
    vector<int>decrease;
    for(auto it:fre){
        if(it.second==1){
            decrease.push_back(it.first);
        }
        else{
            decrease.push_back(it.first);
            increase.push_back(it.first);
        }
    }
    reverse(decrease.begin(),decrease.end());
    for(auto it:increase) cout<<it<<" ";
    for(auto it:decrease) cout<<it<<" ";
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}