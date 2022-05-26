#include<bits/stdc++.h>
using namespace std;

class Solution {
    int dp[601][101][101]={};
    int subProblems(vector<pair<int,int>>&v,int index,int nOnes,int nZeros,int n){
        if(n==index || (nOnes==0 && nZeros==0)){
            return 0;
        }

        if(dp[index][nOnes][nZeros]!=-1){
            return dp[index][nOnes][nZeros];
        }

        if(v[index].first>nOnes || v[index].second>nZeros){
            return subProblems(v,index+1,nOnes,nZeros,n);
        }

        int included=1+subProblems(v,index+1,nOnes-v[index].first,nZeros-v[index].second,n);
        int notIncluded=subProblems(v,index+1,nOnes,nZeros,n);
        return dp[index][nOnes][nZeros] = max(included,notIncluded);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        vector<pair<int,int>>v;
        for(auto&it:strs){
            int one=0,zero=0;
            for(auto&i:it){
                if(i=='1'){
                    one++;
                }
                else{
                    zero++;
                }
            }
            v.push_back({one,zero});
        }
        return subProblems(v,0,n,m,strs.size());
    }
};