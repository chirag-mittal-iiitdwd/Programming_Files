#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& given) {
        sort(given.begin(),given.end(),[&](vector<int>&a,vector<int>&b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }
            return a[0]<b[0];
        });

        vector<int>lis;
        for(int i=0;i<given.size();i++){
            int ele=given[i][1];
            int idx=lower_bound(lis.begin(),lis.end(),ele)-lis.begin();
            if(idx>=lis.size()){
                lis.push_back(ele);
            }
            else{
                lis[idx]=ele;
            }
        }
        return lis.size();
    }
};