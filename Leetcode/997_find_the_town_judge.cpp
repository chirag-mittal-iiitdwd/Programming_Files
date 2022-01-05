#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>>adj(n+1);
        for(auto it:trust){
            adj[it[0]].push_back(it[1]);
        }

        int ansTobe=-1;
        for(int i=1;i<=n;i++){
            if(adj[i].size()==0){
                ansTobe=i;
            }
        }
        if(ansTobe==-1){
            return -1;
        }
        for(int i=1;i<=n;i++){
            if(i!=ansTobe){
                if(find(adj[i].begin(),adj[i].end(),ansTobe)==adj[i].end()){
                    return -1;
                }
            }
        }
        return ansTobe;
    }
};

class Solution2{
    public:
    int findJudge(int n,vector<vector<int>>&trust){
        vector<int>cnt(n+1,0);
        int size=trust.size();
        for(int i=0;i<size;i++){
            cnt[trust[i][0]]=-1;
            cnt[trust[i][1]]++;
        }
        for(int i=1;i<=n;i++){
            if(cnt[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>>trust(m);
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            trust[i].push_back(x);
            trust[i].push_back(y);
        }
        Solution obj;
        cout<<obj.findJudge(n,trust)<<endl;
    }
    return 0;
}