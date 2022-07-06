#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[&](vector<int>&a,vector<int>&b){
            return a[1]>b[1];
        });

        int ans=0;
        for(auto&it:boxTypes){
            if(it[0]>truckSize){
                int availableSpace=truckSize;
                ans+=(it[1]*availableSpace);
                break;
            }
            else{
                ans+=(it[1]*it[0]);
                truckSize-=it[0];
            }
        }

        return ans;
    }
};