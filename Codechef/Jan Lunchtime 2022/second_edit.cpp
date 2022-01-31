#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        for (int i = 0; i < n; i++)
        {
            int req = s[i] - '0';
            if (req + k < 10)
                break;
            k = 10 - req + ((k - 10 + req) / 10) * 10;
            s[i] = '0';
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != '0')
                break;
            ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}