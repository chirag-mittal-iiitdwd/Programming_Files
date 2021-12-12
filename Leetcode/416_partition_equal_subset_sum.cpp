#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2){
            return false;
        }
        int req=sum/2;
        bool t[n+1][req+1];
        memset(t,-1,sizeof(t));
        for(int i=0;i<=n;i++){
            t[i][0]=true;
        }
        for(int i=1;i<=req;i++){
            t[0][i]=false;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=req;j++){
                if(nums[i-1]<=j){
                    t[i][j]=((t[i-1][j])||(t[i-1][j-nums[i-1]]));
                }
                else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[n][req];
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        Solution obj;
        cout<<obj.canPartition(nums)<<endl;
    }
}