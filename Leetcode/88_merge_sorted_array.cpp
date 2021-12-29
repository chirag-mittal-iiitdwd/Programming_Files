#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0;i<n;i++){
            nums1.pop_back();
        }
        int i=0;
        int j=0;
        while(i<m && j<n){
            if(nums1[i]>=nums2[j]){
                nums1.insert(nums1.begin()+i+1,nums2[j]);
                j++;
                m=nums1.size();
            }
            else{
                i++;
            }
        }
        while(j<n){
            nums1.insert(nums1.begin()+i+1,nums2[j]);
            j++;
        }
    }
};