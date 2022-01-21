#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007

class Solution {
    int isValid(vector<int>&piles,int&h,int&i,int&n){
        if(i==0){
            return false;
        }
        int curHr=0;
        // cout<<i<<endl;
        for(int x=0;x<n;x++){
            // cout<<"piles[x]/i : "<<ceil(piles[x]/i)<<endl;
            curHr+=ceil((float)piles[x]/(float)i);
        }
        // cout<<"hr "<<curHr<<endl;
        return curHr;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        if(piles.size()==1){
            int i=1;
            while(true){
                if(h*i>=piles[0]){
                    return i;
                }
                i++;
            }
        }
        sort(piles.begin(),piles.end());
        // for(auto &it:piles){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        int n=piles.size();
        int r=piles[n-1];
        int l=piles[0];

        int ans=r;
        while(l<r){
            int mid=(l+r)/2;
            int curHr=isValid(piles,h,mid,n);
            if(curHr==h){
                ans=mid;
                r--;
            }
            else if(curHr>h){
                l=mid+1;
            }
            else{
                r=mid-1;
                ans=mid;
            }
        }
        return ans;
    }
};

class Solution {
    public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int l = 1, r = 1000000000;
        while (l < r) {
            int m = (l + r) / 2, total = 0;
            for (int p : piles)
                total += (p + m - 1) / m;
            if (total > H)
                l = m + 1;
            else
                r = m;
        }
        return l;
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>piles(n);
        for(int i=0;i<n;i++){
            cin>>piles[i];
        }
        int h;
        cin>>h;
        Solution obj;
        cout<<obj.minEatingSpeed(piles,h)<<endl;
    }
    return 0;
}