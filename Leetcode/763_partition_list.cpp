#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int i=0,n=s.size();

        vector<int>lastIdx(26,0);
        for(int i=0;i<n;i++){
            lastIdx[s[i]-'a']=i;
        }

        vector<int>ans;
        int maxi=0,prev=-1;
        for(int i=0;i<n;i++){
            maxi=max(maxi,lastIdx[s[i]-'a']);
            if(maxi==i){
                ans.push_back(maxi-prev);
                prev=maxi;
            }
        }

        return ans;
    }
};