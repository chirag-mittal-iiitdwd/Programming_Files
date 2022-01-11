#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(i<nums.size() && nums[i]==val){
                nums.erase(nums.begin()+i);
            }
        }
        return nums.size();
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    return 0;
}
