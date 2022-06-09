#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans=left;

        for(int i=left+1;i<=right;i++){
            ans&=i;
        }
        return ans;
    }
};

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int cnt=0;
        while(left!=right){
            right>>=1;
            left>>=1;
            cnt++;
        }
        return left<<cnt;
    }
};