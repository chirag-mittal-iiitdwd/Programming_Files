#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int spaceOptimisation(vector<int> &nums){
        int n = nums.size();
        if (n == 0){
            return 0;
        }

        int prev = max(nums[1], nums[0]), prev2 = nums[0];

        for (int i = 2; i < n; i++){
            int cur = max(prev, prev2 + nums[i]);
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }

    int rob(vector<int> &nums){
        int n = nums.size();
        if (n == 0){
            return 0;
        }
        if (n == 1){
            return nums[0];
        }
        if (n == 2){
            return max(nums[1], nums[0]);
        }
        vector<int> first(n - 1);
        vector<int> second(n - 1);

        for (int i = 0; i < n - 1; i++){
            first[i] = nums[i];
            second[i] = nums[i + 1];
        }
        return ((int)max(spaceOptimisation(first), spaceOptimisation(second)));
    }
};