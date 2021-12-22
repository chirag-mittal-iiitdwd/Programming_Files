#include<bits/stdc++.h>
using namespace std;


// class Solution {
// public:
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         sort(begin(candidates),end(candidates));
//         int n=candidates.size();

//         while(n&&(candidates[n-1]>target)){
//             n--;
//         }

//         int sum=target;
//         vector<vector<int>> result;
//         vector<int> comb;
//         findNextComboSum(candidates,result,comb,n,sum,0);
//         return result;
//     }

//     void findNextComboSum(vector<int>& num,vector<vector<int>>& res,
//                          vector<int>& local,int& n,int sum,int order){
//         if(sum==0){
//             res.push_back(local);
//             return;
//         }
//         else{
//             for(int i=order;i<n;i++){
//                 if(i && num[i-1]==num[i] && i>order){
//                     continue;
//                 }
//                 local.push_back(num[i]);
//                 findNextComboSum(num,res,local,n,sum-num[i],i);
//                 local.pop_back();
//             }
//         }
//     }
// };

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) 
    {
        vector<vector<int>> res;
        sort(num.begin(),num.end());
        vector<int> local;
        findCombination(res, 0, target, local, num);
        return res;
    }
    void findCombination(vector<vector<int>>& res,int order,int target, vector<int>& local,vector<int>& num)
    {
        if(target==0)
        {
            res.push_back(local);
            return;
        }
        else
        {
            for(int i = order;i<num.size();i++)
            {
                if(num[i]>target) return;
                if(i&&num[i]==num[i-1]&&i>order) continue;
                local.push_back(num[i]),
                findCombination(res,i+1,target-num[i],local,num);
                local.pop_back();
            }
        }
    }
};