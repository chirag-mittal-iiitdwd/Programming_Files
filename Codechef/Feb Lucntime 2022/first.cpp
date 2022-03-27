#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007

static bool comp(pair<int,char>&a,pair<int,char>&b){
    if(a.first<b.first){
        return true;
    }
    else{
        if(a.second<b.second){
            return true;
        }
        return false;
    }
}

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
        for(int i=0;i<n;i++){
            cin>>v[i];
        }

        string str;
        cin>>str;
        
        vector<pair<int,char>>vp;
        for(int i=0;i<n;i++){
            vp.push_back({v[i],str[i]});
        }

        vector<pair<int,char>>svp=vp;
        sort(svp.begin(),svp.end(),comp);

        int i=0;
        while(i<n){
            if(svp[i].first==vp[i].first){
                i++;
            }
            else{
                break;
            }
        }

        bool isPossible=true;
        int ans=0;
        int lastDifferentPole=-1;
        int prevPole=-1;
        int j=i;
        while(j<n){
            i=j;
            prevPole=lastDifferentPole;
            char curPole=vp[j].second;
            while(i<n){
                if(curPole!=vp[i].second){
                    lastDifferentPole=i;
                }
            }
            if(lastDifferentPole!=prevPole){
                sort(vp.begin()+j,vp.begin()+lastDifferentPole,comp);
                ans++;
                if(lastDifferentPole==n-1){
                    j=n-1;
                }
                else{
                    j++;
                }
            }
            else{
                isPossible=false;
                break;
            }
        }

        if(isPossible){
            cout<<ans<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    return 0;
}