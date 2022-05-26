#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int threeSumMulti(vector<int>& nums, int target) {
        map<int,long>mp;
        for(auto&it:nums){
            mp[it]++;
        }

        long ans=0;
        for(auto&it:mp){
            for(auto&it2:mp){
                int i=it.first,j=it2.first,k=target-i-j;
                if(mp.count(k)==0){
                    continue;
                }
                if(i==j && j==k){
                    ans+=(mp[i]*(mp[i]-1)*(mp[i]-2))/6;
                }
                else if(i==j && j!=k){
                    ans+=(mp[i]*(mp[i]-1)/2)*mp[k];
                }
                else if(i<j && j<k){
                    ans+=mp[i]*mp[j]*mp[k];
                }
            }
        }

        return (int)(ans%(1000000007));
    }
};