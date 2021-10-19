#include<bits/stdc++.h>
using namespace std;

void auxilary(vector<int>a,vector<vector<int>>&ans,int idx){
    if(idx==a.size()){
        ans.push_back(a);
        return;
    }
    for(int i=idx;i<a.size();i++){
        if(i!=idx && a[i]==a[idx]){
            continue;
        }
        swap(a[i],a[idx]);
        auxilary(a,ans,idx+1);
        // swap(a[i],a[idx]);
    }
}

vector<vector<int>>permute(vector<int>nums){
    sort(nums.begin(),nums.end());
    vector<vector<int>>ans;
    auxilary(nums,ans,0);
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<vector<int>>ans=permute(nums);
    for(auto it:ans){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}