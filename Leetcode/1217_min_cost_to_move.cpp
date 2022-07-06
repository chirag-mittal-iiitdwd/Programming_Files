#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int even=0,odd=0;
        for(auto&it:position){
            if(it&1){
                odd++;
            }
            else{
                even++;
            }
        }
        return min(even,odd);
    }
};