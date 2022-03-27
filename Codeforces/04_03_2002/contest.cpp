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
        vector<int>v(n);

        int bsum=0;
        for(int i=0;i<n;i++){
            cin>>v[i];
            bsum+=v[i];
        }

        sort(v.begin(),v.end());

        int bcnt=n,rcnt=0,rsum=0;
        // cout<<"blue count : "<<bcnt<<endl;
        // cout<<"red count : "<<rcnt<<endl;
        // cout<<"blue sum : "<<bsum<<endl;
        // cout<<"red sum : "<<rsum<<endl;
        // cout<<endl;
        // cout<<endl;

        bool ans=false;
        for(int i=n-1;i>=(n/2)-1;i--){
            bsum-=v[i];
            rsum+=v[i];
            bcnt--;
            rcnt++;
        //     cout<<"blue count : "<<bcnt<<endl;
        // cout<<"red count : "<<rcnt<<endl;
        // cout<<"blue sum : "<<bsum<<endl;
        // cout<<"red sum : "<<rsum<<endl;
        // cout<<endl;
        // cout<<endl;
            if(bsum<rsum && rcnt<bcnt){
        //         cout<<"blue count : "<<bcnt<<endl;
        // cout<<"red count : "<<rcnt<<endl;
        // cout<<"blue sum : "<<bsum<<endl;
        // cout<<"red sum : "<<rsum<<endl;
        // cout<<endl;
        // cout<<endl;
                ans=true;
                break;
            }
        }

        if(ans){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}