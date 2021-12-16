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
        bool flag=true;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(i!=0 && arr[i]!=arr[i-1]){
                flag=false;
            }
        }
        if(flag || n==1){
            cout<<0<<"\n";
        }
        else{
            int maxEle=*max_element(arr.begin(),arr.end());
            // int pos=-1;
            // for(int i=0;i<n;i++){
            //     if(maxEle==arr[i]){
            //         pos=i;
            //         break;
            //     }
            // }
            if(arr[n-1]==maxEle){
                cout<<1<<"\n";
            }
            else{
                cout<<2<<"\n";
            }
        }
    }
    return 0;
}