#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1000000000000000000

void solve(int tc)
{
    int n,x;
    cin >> n >> x;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    int mx[n+1];
    for(int i=0;i<=n;i++)
    {
        mx[i]=-INF;
    }
    for(int i=0;i<n;i++)
    {
        int s=0;
        for(int j=i;j<n;j++)
        {
            s+=a[j];
            mx[j-i+1]=max(mx[j-i+1],s);
        }
    }

    int ans[n+1];
    for(int i=0;i<=n;i++)
    {
        ans[i]=0;
    }
    for(int i=0;i<=n;i++) // Size of subarray
    {
        for(int j=0;j<=n;j++) // Value Of K
        {
            ans[j]=max(ans[j],mx[i]+min(i,j)*x);
        }
    }
    for(int i=0;i<=n;i++)
        cout << ans[i] << " ";
    cout << '\n';
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc=1;
    cin >> tc;
    for(int ttc=1;ttc<=tc;ttc++)
        solve(ttc);
    return 0;
}