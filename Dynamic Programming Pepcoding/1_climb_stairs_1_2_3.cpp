#include<bits/stdc++.h>
using namespace std;

class Solution{
    int cba(vector<int>&dp,int n){
        if(dp[n]!=-1){
            return dp[n];
        }
        else{
            dp[n]=cba(dp,n-1)+cba(dp,n-2)+cba(dp,n-3);
        }
        return dp[n];
    }
    public:
    int cbb(int n){
        if(n<=3){
            if(n<=2){
                return n;
            }
            else{
                return 4;
            }
        }
        else{
            vector<int>dp(n+1,-1);
            dp[0]=0;
            dp[1]=1;
            dp[2]=2;
            dp[3]=4;
            return cba(dp,n);
        }
    }
};

int main(){
        int n;
        cin>>n;
        Solution obj;
        cout<<obj.cbb(n)<<endl;
}