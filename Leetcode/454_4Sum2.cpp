#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n=nums3.size();

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    for(int l=0;l<n;l++){
                        if((nums1[i]+nums2[j]+nums3[k]+nums4[l])==0){
                            ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        map<int,int>mp;

        for(auto&it:nums1){
            for(auto&i:nums2){
                mp[i+it]++;
            }
        }

        int cnt=0;
        for(auto&it:nums3){
            for(auto&i:nums4){
                cnt+=mp[-(it+i)];
            }
        }
        return cnt;
    }
};