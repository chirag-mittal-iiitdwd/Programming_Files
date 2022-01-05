#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        vector<vector<int>>ans(rowIndex+1);
        for(int i=0;i<=rowIndex;i++){
            ans[i].resize(i+1);
            ans[i][0]=ans[i][i]=1;
            for(int j=1;j<i;j++){
                ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
            }
        }
        
        return ans[rowIndex];
    }
};

class Solution2 {
public:
    vector<int> getRow(int rowIndex) {
        ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        vector<int>res(rowIndex+1,1);
        for(int i=1;i<rowIndex;i++){
            for(int j=i;j>0;j--){
                res[j]+=res[j-1];
            }
        }
        return res;
    }
};

class Solution3{
    public:
    vector<int>getRow(int rowIndex){
        vector<int>res;
        res.push_back(1);
        int coff=1;
        for(int i=1;i<=rowIndex;i++){
            coff=coff*(rowIndex-i+1)/i;
            res.push_back(coff);
        }
        return res;
    }
};