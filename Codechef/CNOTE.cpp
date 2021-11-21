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
        int x,y,k,n;
        cin>>x>>y>>k>>n;
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            int p,c;
            cin>>p>>c;
            v.push_back({p,c});
        }
        int leftOverPages=x-y;
        bool flag=false;
        for(auto &it:v){
            if(it.first>=leftOverPages && it.second<=k){
                flag=true;
                break;
            }
        }
        if(flag){
            cout<<"LuckyChef"<<endl;
        }
        else{
            cout<<"UnluckyChef"<<endl;
        }
    }
    return 0;
}