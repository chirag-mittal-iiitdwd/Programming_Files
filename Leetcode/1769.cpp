#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int>ans(n);

        for(int i=0;i<n;i++){
            int tempAns=0;
            for(int j=0;j<n;j++){
                if(i==j){
                    continue;
                }
                if(boxes[i]=='1'){
                    tempAns+=abs(i-j);
                }
            }
            ans[i]=tempAns;
        }

        return ans;
    }
};