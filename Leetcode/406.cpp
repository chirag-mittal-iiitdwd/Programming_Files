#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),[&](vector<int>&a,vector<int>&b){
            return a[0]>b[0] || (a[0]==b[0] && a[1]<b[1]);
        });

        for(auto&it:people){
            cout<<it[0]<<" "<<it[1]<<endl;
        }

        vector<vector<int>>ans;
        for(auto&it:people){
            ans.insert(ans.begin()+it[1],it);
        }
        return ans;
    }
};