#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int>s;
        for(auto &it:nums){
            s.insert(it);
        }
        return s.size()!=nums.size();
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    return 0;
}