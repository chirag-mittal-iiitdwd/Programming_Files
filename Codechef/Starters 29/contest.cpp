#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int>q(n);
    for(int i=0;i<n;i++){
        cin>>q[i];
    }

    vector<vector<int>>rxns(m);
    for(int i=0;i<m;i++){
        int start,num;
        cin>>start>>num;

        int x=2*num+2;
        rxns[i].resize(x);
        rxns[i][0]=start;
        rxns[i][1]=num;
        for(int j=2;j<x;j++){
            int inp;
            cin>>inp;
            rxns[i][j]=inp;
        }
    }

    for(int i=0;i<m;i++){
        int qIdx=rxns[i][0]-1,prods=rxns[i][1];
        int qCnt=q[qIdx];
        int x=(prods*2)+2;
        if(qCnt>0){
            q[qIdx]=0;
            for(int j=2;j<x;j+=2){
                int prodId=rxns[i][j+1]-1;
                q[prodId]=(q[prodId]+(rxns[i][j]*qCnt))%mod;
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<q[i]<<endl;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}