#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007

bool check(vector<int>arr,int first,int last){
    sort(arr.begin()+first,arr.begin()+last+1);
    if(is_sorted(arr.begin(),arr.end())){
        return true;
    }
    return false;
}

void solve(){
        int n;
        cin>>n;
        int nCnt=0;
        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }

        string str;
        cin>>str;

        for(int i=0;i<n;i++){
            if(str[i]=='N'){
                nCnt++;
            }
        }

        if(nCnt==0 || nCnt==n){
            cout<<-1<<endl;
            return;
        }

        if(is_sorted(v.begin(),v.end())){
            cout<<0<<endl;
            return;
        }

        int firstN=-1,firstS=-1,lastN=-1,lastS=-1;
        for(int i=0;i<n;i++){
            if(str[i]=='S'){
                if(firstS==-1){
                    firstS=i;
                }
                lastS=i;
            }
            else{
                if(firstN==-1){
                    firstN=i;
                }
                lastN=i;
            }
        }
int ans = 2;
    if(check(v, firstN, lastS) || check(v, firstS, lastN)) {
        ans = 1;
    }
    cout << ans << endl;

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
    solve();
    }
    return 0;
}