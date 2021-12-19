#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
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

        vector<int>f;
        vector<int>s;
        for(int i=0;i<n;i++){
            if(i&1){
                f.push_back(arr[i]);
            }
            else{
                s.push_back(arr[i]);
            }
        }
        // for(auto)
        int n1=f.size();
        int n2=s.size();
        int pos1=((n1+1)/2)-1;
        int pos2=((n2+1)/2)-1;
        // cout<<f[pos1]<<" "<<s[pos2]<<endl;
        cout<<abs(f[pos1]-s[pos2])<<endl;
    }
    return 0;
}