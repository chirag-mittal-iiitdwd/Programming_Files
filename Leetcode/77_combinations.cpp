#include<bits/stdc++.h>
using namespace std;

class Solution {
    void helper(vector<vector<int>>&ans,vector<int>test,int j,int n,int k){
        if(test.size()==k){
            ans.push_back(test);
            return;
        }

        for(int i=j;i<=n;i++){
            test.push_back(i);
            if(test.size()>1 && test[test.size()-1]<=i){
                cout<<"exe ";
                test.pop_back();
                continue;
            }
            cout<<"test : ";
            for(int x=0;x<test.size();x++){
                cout<<test[x]<<" ";
            }
            helper(ans,test,j+1,n,k);
            test.pop_back();
            cout<<"test : ";
            for(int x=0;x<test.size();x++){
                cout<<test[x]<<" ";
            }
            cout<<endl;
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        helper(ans,{},1,n,k);
        return ans;   
    }
};

// [1,2],
// [1,3],
// [1,4],
// [2,2],
// [2,3],
// [2,4],
// [3,2],
// [3,3],
// [3,4],
// [4,2],
// [4,3],
// [4,4]