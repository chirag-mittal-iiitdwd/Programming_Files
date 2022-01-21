#include<bits/stdc++.h>
using namespace std;
// #define int long long int
#define mod 1000000007

// class Solution {
// public:
//     int minJumps(vector<int>& arr) {
//         int n=arr.size();
//         unordered_map<int,set<int>>mp;
//         vector<int>dp(n,INT_MAX);
//         dp[n-1]=0;
//         mp[arr[n-1]].insert(n-1);
//         for(int i=n-2;i>=0;i--){
//             // cout<<arr[i]<<" : i : "<<i<<"mp.size"<<mp[arr[i]].size()<<endl;
//             if(i==n-2){
//                 dp[i]=1;
//                 mp[arr[i]].insert(i);
//                 continue;
//             }
//             if(arr[i]==arr[n-1]){
//                 dp[i]=1;
//             }
//             else if(i-1>=0 && arr[i-1]==arr[n-1]){
//                 dp[i]=min(dp[i],2);
//             }
//             else if(arr[i+1]==arr[n-1]){
//                 dp[i]=min(dp[i],2);
//             }
//             else if(mp[arr[i]].size()>0){
//                 // cout<<"exe"<<arr[i]<<endl;
//                 int minVal=INT_MAX-1;
//                 for(auto &it:mp[arr[i]]){
//                     minVal=min(minVal,dp[it]);
//                 }
//                 // cout<<arr[i]<<" : "<<lastOcc<<endl;
//                 // dp[i]=1+minVal;
//                 dp[i]=min(dp[i],1+minVal);
//             }
//             else{
//                 // cout<<mp[22].size()<<endl;
//                 // cout<<"exe"<<arr[i]<<endl;
//                 dp[i]=min(dp[i],1+dp[i+1]);
//             }
//             mp[arr[i]].insert(i);
//         }
//         // for(int i=0;i<n;i++){
//         //     cout<<dp[i]<<" ";
//         // }
//         // cout<<endl;
//         return dp[0];
//     }
// };

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> indicesOfValue;
        for (int i = 0; i < n; i++){
            indicesOfValue[arr[i]].push_back(i);
        }

        vector<bool> visited(n); 
        visited[0] = true;
        queue<int> q; 
        q.push(0);
        int step = 0;
        while (!q.empty()) {
            for (int size = q.size(); size > 0; --size) {
                int i = q.front(); 
                q.pop();
                if (i == n - 1){ 
                    return step;
                }
                vector<int>& next = indicesOfValue[arr[i]];
                next.push_back(i - 1); next.push_back(i + 1);
                for (int j : next) {
                    if (j >= 0 && j < n && !visited[j]) {
                        visited[j] = true;
                        q.push(j);
                    }
                }
                next.clear();
            }
            step++;
        }
        return 0;
    }
};

