#include<bits/stdc++.h>
using namespace std;
// #define int long long int
#define mod 1000000007
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        double ans=arr[n-1];
        double avg=0;
        for(auto &it:arr){
            avg+=it;
        }
        avg-=arr[n-1];
        avg=(avg/double(n-1));
        ans+=avg;
        cout << fixed << setprecision(6) << ans<< endl;
    }
    return 0;
}