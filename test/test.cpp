#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace std::chrono;

class Solution {
public:
    string reverseBits(uint32_t n) {
        uint64_t ans=0;
        string ans1;
        vector<int>arr(32,0);
        for(int i=0;i<=63;i++){
            bool x=n&(1<<63-i);
            if(x){
                arr[i]=1;
            }
            else{
                arr[i]=0;
            }
            for(auto &it:arr){
                cout<<it<<" ";
            }
            cout<<endl;
            // cout<<ans1<<endl;
            // ans=ans|(x<<i);
        }
        return ans1;
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    uint64_t n=9223372036854775807;
    Solution obj;

    auto start = high_resolution_clock::now();
    cout<<obj.reverseBits(n)<<endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout<<duration.count()<<endl;


    return 0;
}