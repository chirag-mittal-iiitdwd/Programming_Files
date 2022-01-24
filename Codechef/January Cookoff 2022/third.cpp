#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007

int LongestIncreasingSubsequenceLength(std::vector<int>& v)
{
    if (v.size() == 0)
        return 0;
 
    std::vector<int> tail(v.size(), 0);
    int length = 1;
 
    tail[0] = v[0];
 
    for (int i = 1; i < v.size(); i++) {
        auto b = tail.begin(), e = tail.begin() + length;
        auto it = upper_bound(b, e, v[i]);
 
        if (it == tail.begin() + length)
            tail[length++] = v[i];
        else
            *it = v[i];
    }
 
    return length;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        vector<int>b(m);
        for(int i=0;i<m;i++){
            cin>>b[i];
        }

        vector<int>x;
        int i=0;
        int j=0;
        while(i<n && j<m){
            if(a[i]<b[j]){
                x.push_back(a[i]);
                i++;
            }
            else{
                x.push_back(b[j]);
                j++;
            }
        }

        while(i<n){
            x.push_back(a[i]);
            i++;
        }

        while(j<m){
            x.push_back(b[j]);
            j++;
        }
        for(auto &it:x){
            cout<<it<<" ";
        }
        cout<<endl;
        cout<<LongestIncreasingSubsequenceLength(x)<<endl;
    }
    return 0;
}