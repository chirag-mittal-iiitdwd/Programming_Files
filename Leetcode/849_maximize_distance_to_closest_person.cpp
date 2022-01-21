#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int>filled;
        int n=seats.size();
        for(int i=0;i<n;i++){
            if(seats[i]==1){
                filled.push_back(i);
            }
        }

        int maxDist=0;
        for(int i=0;i<n;i++){
            if(seats[i]==0){
                int mini=INT_MAX;
                for(auto&it:filled){
                    mini=min(mini,abs(it-i));
                }
                if(mini!=INT_MAX){
                    maxDist=max(maxDist,mini);
                }
            }
        }

        return maxDist;
    }
};

class Solution2{
    public:
    int maxDistToClosest(vector<int>&seats){
        int ans=INT_MIN;
        int n=seats.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(seats[i]==0){
                count++;
            }
            else{
                ans=max(ans,count);
                count=0;
            }
        }
        ans=max(ans,count);

        int right=0;
        count=0;
        for(int i=n-1;i>=0;i--){
            if(seats[i]==0){
                count++;
            }
            else{
                break;
            }
        }
        right=max(right,count);

        int left=0;
        count=0;
        for(int i=0;i<n;i++){
            if(seats[i]==0){
                count++;
            }
            else{
                break;
            }
        }
        left=max(left,count);

        ans=(ans+1)/2;
        ans=max(ans,left);
        ans=max(ans,right);
        return ans;
    }
};

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int tmp = 0;
        int ans = 0;
        int fans = -1;
        for(auto x : seats){
            if(x==1){
                if(fans==-1){ 
                    fans = max(ans,tmp);
                }
                ans = max(ans,tmp);
                tmp = 0;
            }
            else{
                tmp++;
            }
        }
        return max({tmp,fans,(ans+1)/2});
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    return 0;
}