#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,vector<int>>mp;
        int n=nums.size();

        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }

        for(auto &it:mp){
            if(it.second.size()>1){
                for(int i=1;i<it.second.size();i++){
                    if(it.second[i]-it.second[i-1]<=k){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>last_seen;

        for(int i=0;i<n;i++){
            if(last_seen.count(nums[i]) && (i-last_seen[nums[i]]<=k)){
                return true;
            }
            last_seen[nums[i]]=i;
        }
        return false;
    }
};


// Sliding Window Technique
class Solution{
    public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int>s;
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(s.count(nums[i])){
                return true;
            }
            s.insert(nums[i]);
            if(s.size()>k){
                s.erase(nums[i-k]);
            }
        }

        return false;
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    return 0;
}