#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans=string(n,'a');
        k-=n;

        int idx=n-1;
        while(k>0){
            int toAdd=min(k,25);
            k-=toAdd;
            ans[idx]+=toAdd;
            idx--;
        }
        return ans;
    }
};