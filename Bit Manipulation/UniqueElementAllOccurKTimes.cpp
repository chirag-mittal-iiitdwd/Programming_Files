#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int singleNumber(const vector<int> &A, int k){
        int n = A.size();
        int count[32] = {0};
        int result = 0;
        for (int i = 0; i < 32; i++){
            for (int j = 0; j < n; j++){
                if ((A[j] >> i) & 1){
                    count[i]++;
                }
            }
            result |= ((count[i] % k) << i);
        }
        return result;
    }
};

int main()
{
    Solution *x = new Solution();
    vector<int> y = {1};
    cout << x->singleNumber(y, 3);
}