#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isSelfDividing(int n){
        int cpy=n;
        while(n){
            int rem=n%10;
            if((cpy%rem)!=0){
                return false;
            }
            n/=10;
        }
        return true;
    }
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>ans;
        for(int i=left;i<=right;i++){
            if(isSelfDividing(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};