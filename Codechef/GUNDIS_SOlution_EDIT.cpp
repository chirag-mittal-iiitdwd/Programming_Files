#include <bits/stdc++.h>
#define fast_io std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> matrix;

const int mod = 1000000007;
const long double ratio32 = 1.0 / log2(3);

// The product will not fit inside the numerical data types of most languages. However since the product if of form 2^x * 3^y, we can keep store the count of $x$ and $y$ instead of the product, and use logarithm to compare products.
bool comp(pll a, pll b)
{
    return (a.first + a.second * ratio32) < (b.first + b.second * ratio32);
}

int sum = 0;
void ca()
{
    ll n;
    cin >> n;
    sum += n;
    ll a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // compress array
    // [7 7 7 7 7] 2 2 2 3
    // 7 7 2 2 3

    // Since for each dp state we will iterate backwards till we find 3 unique elements, this could take $O(n^2)$ worst case time when there are large number of identical elements in array. To correct this, we will *compress* the array.

    // Consider a subarray consisting of only identical elements like - $[7, 7, 7, 7, 7]$. In optimal division, this subarray will either be part of one larger subarray or it will be broken in two and divided between two adjacent subarrays. In first case it will provide $7$ to large subarray, and in second case a $7$ each to adjacent subarrays. If we replaced the subarray of $7s$ with just $[7, 7]$ then the situation will still be identical, it could be  part of a single larger subarray or two adjacent subarrays and provide them with a $7$ each. That is for any subarray of identical elements larger in size than $3$, we can replace it with just two of those identical elements.

    // Doing this *compression* ensures that every $3$ elements contains atleast $2$ unique elements so our worst case is handled.
    vector<ll> arr;
    arr.push_back(0);
    for (int i = 0; i < n && i < 2; i++)
        arr.push_back(a[i]);
    for (int i = 2; i < n; i++)
    {
        int m = arr.size();
        if (!(a[i] == arr[m - 1] && a[i] == arr[m - 2]))
            arr.push_back(a[i]);
    }
    n = arr.size() - 1; // -1 for 1 indexing

    vector<pll> dp(n + 1);
    map<int, int> seen;

    dp[0] = {0, 0}; // number of 3, number of 2

    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1]; // Take no element
        set<ll> seen;
        // we could go backwards beyond 6 in case of 1, 2, 1, 2, 1, 2, 1, 2 ...
        // however making a subarray larger than 6 elements is suboptimal, so we check it
        for (int j = i; j > max(0, i - 6); j--)
        {
            seen.insert(arr[j]);
            if (seen.size() == 2)
                dp[i] = max(dp[i],
                            (pll){dp[j - 1].first,
                                  dp[j - 1].second + 1},
                            comp);
            else if (seen.size() == 3)
            {
                dp[i] = max(dp[i],
                            (pll){dp[j - 1].first + 1,
                                  dp[j - 1].second},
                            comp);
                break;
            }
        }
    }
    ll ans = 1;
    for (int i = 0; i < dp[n].second; i++)
        (ans *= 2) %= mod;
    for (int i = 0; i < dp[n].first; i++)
        (ans *= 3) %= mod;
    cout << (ans) << endl;
}

int main()
{
    fast_io;
    int t;
    cin >> t;
    while (t--)
        ca();
}