/*
    custom comparators : https://www.youtube.com/watch?v=zBhVZzi5RdU 40:00
    In this question used a different way to impliment custom comparators
    We are given with tasks ans we want to fins how many tasks we can 
    do if we are given with starting and ending time for each task and
    we can do only one task at a time

    Greedy
    if you are at the ith activity
    What should be your next step?
    Take the next activity which ends first
*/
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<pair<int,int>> activitySelectionProblem(vector<pair<int,int>>&p){
        sort(p.begin(),p.end(),[&](pair<int,int>&a,pair<int,int>&b){
            return a.second<b.second;
        });
        vector<pair<int,int>>ans;
        int end=0;
        for(auto &it:p){
            if(end<=it.first){
                ans.push_back({it.first,it.second});
                end=it.second;
            }
        }
        return ans;
    }
};
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>>p;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        p.push_back({a,b});
    }
    // sort(p.begin(),p.end(),[&](pair<int,int>&a,pair<int,int>&b){
    //     return a.second<b.second;
    // });
    // int ans=0;
    // int end=0;
    // for(auto it:p){
    //     if(end<=it.first){
    //         ans++;
    //         end=it.second;
    //     }
    // }
    // cout<<ans<<endl;
    Solution obj;
    vector<pair<int,int>>ans=obj.activitySelectionProblem(p);
    if(ans.size()==0){
        cout<<"No Work Con Be Done\n";
    }
    else{
        cout<<ans.size()<<" Works can be done\n";
        for(auto &it:ans){
            cout<<it.first<<" "<<it.second<<endl;
        }
    }
    cout<<endl;

    return 0;
}