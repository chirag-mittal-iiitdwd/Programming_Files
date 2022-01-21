#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int k) {
        flowerbed.insert(flowerbed.begin(),0);
        flowerbed.push_back(0);
        int n=flowerbed.size();

        for(int i=1;i<n-1;i++){
            if(flowerbed[i-1]+flowerbed[i]+flowerbed[i+1]==0){
                k--;
                i++;
            }
        }

        return k<=0;
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    return 0;
}