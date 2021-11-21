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
        int n,m;
        cin>>n>>m;
        vector<int>tasks(n+1,-1);
        for(int i=0;i<m;i++){
            int x;
            cin>>x;
            tasks[x]=1;
        }
        vector<int>chef;
        vector<int>assist;
        bool flag=true;
        for(int i=1;i<=n;i++){
            if(tasks[i]==-1){
                if(flag){
                    chef.push_back(i);
                    flag=false;
                }
                else{
                    assist.push_back(i);
                    flag=true;
                }
            }
        }
        for(auto &it:chef){
            cout<<it<<" ";
        }
        cout<<endl;
        for(auto &it:assist){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    return 0;
}