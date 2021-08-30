#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m, k;
        cin>>n>>m>>k;
        vector<pair<int, int>> moves;
        for(int i=0; i<n*m; i++){
            int x, y;
            cin>>x>>y;
            moves.push_back({x, y});
        }
        int low=0, high = n*m - 1, ans=n*m;
        while(low <= high){
            int mid = (low + high)/2;
            int a[n+1][m+1];
            for(int i=0; i<=n; i++){
                for(int j=0; j<=m; j++){
                    a[i][j] = 0;
                }
            }
            for(int i=0; i<=mid; i++){
                if(i%2 == 0)
                    a[moves[i].first][moves[i].second] = 1;
                else
                    a[moves[i].first][moves[i].second] = -1;
            }
            for(int i=1; i<=n; i++){
                for(int j=1; j<=m; j++)
                {
                    a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
                }
            }
            bool found = false;
            for(int i=k; i<=n; i++){
                for(int j=k; j<=m; j++)
                {
                    int cnt = a[i][j] - a[i-k][j] - a[i][j-k] + a[i-k][j-k];
                    if(abs(cnt) == k*k)
                        found = true;
                }
            }
            if(found){
                ans = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        if(ans == n*m)
            cout<<"Draw\n";
        else if(ans%2 == 0)
           cout<<"Alice\n";
        else
            cout<<"Bob\n";
    }
}