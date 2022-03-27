#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> A(n);
    for (int i = 0; i < n; i++){
        cin >> A[i];
    }
    while (m--){
        ll c, x;
        cin >> c >> x;
        vector<ll> u(2 * x);
        for (int i = 0; i < 2 * x; i++){
            cin >> u[i];
        }
        ll temp = A[c - 1];
        A[c - 1] = 0;
        for (int i = 0; i < u.size() - 1; i += 2){
            A[u[i + 1] - 1] = (A[u[i + 1] - 1] + temp * u[i]) % mod;
        }
    }
    for (auto x : A)
        cout << x << "\n";
    return 0;
}