#include<bits/stdc++.h>
using namespace std;
#define int long long int
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

        int ans=0;
        int end=0;
        int toMake=arr[n-1];
        for(int i=n-1;i>=0;i--){
            if(toMake==arr[i]){
                end++;
            }
            else{
                ans++;
                i-=end;
                i++;
                end+=end;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}