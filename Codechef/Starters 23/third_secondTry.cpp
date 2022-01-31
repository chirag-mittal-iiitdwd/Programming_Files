#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    scanf("%d",&t);
    while(t--){
        int n,x;
        scanf("%d%d",&n,&x);
        string str;
        cin>>str;

        vector<int>sub;
        int start=0,cur=0;
        for(int i=0;i<n;i++){
            if(str[i]=='0'){
                if(cur==0){
                    start=i;
                }
                cur++;
            }
            else{
                sub.push_back(i-start);
                cur=0;
            }
        }
        if(cur!=0){
            sub.push_back(n-start);
        }
        if(sub.size()==0 && x==1){
            cout<<1<<endl;
        }
        else{
            int ans=0;
            int flag=true;
            for(int i=0;i<sub.size();i++){
                int norm=sub[i]/x;
                int extend=(sub[i]+1)/x;
                int merge=-1;
                if(i+1<sub.size()){
                    
                }
            }
        }
    }
    return 0;
}