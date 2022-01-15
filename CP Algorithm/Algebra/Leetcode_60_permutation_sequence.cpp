#include<bits/stdc++.h>
using namespace std;
#define int long long int

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>nums;
        int fact=1;
        for(int i=1;i<n;i++){
            fact*=i;
            nums.push_back(i);
        }
        nums.push_back(n);

        string ans{""};
        k--;
        while(true){
            ans+=to_string(nums[k/fact]);
            nums.erase(nums.begin()+(k/fact));
            if(nums.size()==0){
                break;
            }
            k%=fact;
            fact/=nums.size();
        }
        return ans;
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    return 0;
}