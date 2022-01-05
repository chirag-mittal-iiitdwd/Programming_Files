#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int r=numbers.size()-1;
        int l=0;
        while(numbers[r]>=target){
            r--;
        }
        while(l<r){
            int sum=numbers[l]+numbers[r];
            if(sum==target){
                return {l+1,r+1};
            }
            else if(sum>target){
                r--;
            }
            else{
                l++;
            }
        }
        return {};
    }
};

class Solution2{
    public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        int r=numbers.size()-1;
        int l=0;
        while(l<r){
            int sum=numbers[l]+numbers[r];
            int mid=(l+r)/2;
            if(sum==target){
                return {left+1,right+1};
            }
            else if(numbers[mid]+numbers[r]<target){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return {};
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    return 0;
}