#include<bits/stdc++.h>
using namespace std;
// #define int long long int

class Solution {
    bool static comp(pair<int,int>&a,pair<int,int>&b){
        if(a.second<b.second){
            return true;
        }
        else{
            if(a.second==b.second){
                return a.first<b.first;
            }
            return false;
        }
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        ios_base::sync_with_stdio(false);
        int n=points.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({points[i][0],points[i][1]});
        }
        sort(v.begin(),v.end(),comp);
        
        for(auto &it:v){
            cout<<it.first<<" "<<it.second<<endl;
        }
        int arrows=1;
        int curEnd=v[0].second;
        int i=1;
        while(i<n){
            if(v[i].first<=curEnd){
                i++;
            }
            else{
                arrows++;
                curEnd=v[i].second;
                i++;
            }
        }

        return arrows;
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){

    }
    return 0;
}