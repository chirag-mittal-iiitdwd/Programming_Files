#include<bits/stdc++.h>
using namespace std;

#define ll long long int
class Solution {
    bool static comp(const pair<int,int>&a,const pair<int,int>&b){
        ll sq1=(pow(a.first,2)+pow(a.second,2));
        ll sq2=(pow(b.first,2)+pow(b.second,2));
        if(sq1<sq2){
            return true;
        }
        else{
            return false;
        }
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k){
        vector<pair<int,int>>p;
        for(auto &it:points){
            p.push_back({it[0],it[1]});
        }
        sort(p.begin(),p.end(),comp);

        vector<vector<int>>ans(k);
        for(int i=0;i<k;i++){
            ans[i].push_back(p[i].first);
            ans[i].push_back(p[i].second);
        }
        return ans;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>>v;
        for(int i=0;i<n;i++){
            int p,q;
            cin>>p>>q;
            v[i].push_back(p);
            v[i].push_back(q);
        }

        Solution obj;
        vector<vector<int>>z=obj.kClosest(v,k);
        for(auto &it:z){
            cout<<it[0]<<" "<<it[1]<<endl;
        }
    }
}