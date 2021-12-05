#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    double findMedianSortedArrays(vector<int>&nums1,vector<int>&nums2){
        vector<int>arr;
        auto i=nums1.begin();
        auto j=nums2.begin();
        while(i<nums1.end() && j<nums2.end()){
            if(*i<*j){
                arr.push_back(*i);
                i++;
            }
            else{
                arr.push_back(*j);
                j++;
            }
        }
        while(j<nums2.end()){
            arr.push_back(*j);
            j++;
        }
        while(i<nums1.end()){
            arr.push_back(*i);
            i++;
        }
        double ans=0;
        int n=arr.size();
        for(auto it:arr){
            cout<<it<<" ";
        }
        cout<<endl;
        if((arr.size()%2)==0){
            int first=arr[n/2];
            int second=arr[(n/2)-1];
            cout<<first<<" "<<second<<endl;
            ans=(first+second)/(double)2;
        }
        else{
            ans=(double)arr[n/2];
        }
        return ans;
    }
};

int main(){
    int n1,n2;
    cin>>n1>>n2;
    vector<int>nums1(n1);
    vector<int>nums2(n2);
    for(int i=0;i<n1;i++){
        cin>>nums1[i];
    }
    for(int i=0;i<n2;i++){
        cin>>nums2[i];
    }

    Solution obj;
    cout<<obj.findMedianSortedArrays(nums1,nums2)<<endl;
}