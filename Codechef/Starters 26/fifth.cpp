#include <bits/stdc++.h>
using namespace std;
#define int long long 

#define endl "\n"

void solve() {
    int N; cin >> N;
    string A, B; cin >> A >> B;
    vector<char> ans(2 * N);
    int front = 0, back = 2 * N - 1;
    int startA = 0, endA = N-1, startB = 0, endB = N-1;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    reverse(B.begin(), B.end());
    
    for(int i = 0; i < 2*N; i ++) {
        if((i % 2) == 0) { // Current Turn = Alice
            if(A[startA] >= B[startB]) {
                ans[back --] = A[endA --];
            }
            else {
                ans[front ++] = A[startA ++];
            }
        }
        else { // Bob Turn
            if(A[startA] < B[startB]) {
                ans[front ++] = B[startB ++];
            }
            else {
                ans[back --] = B[endB --];
            }
        }
    }
    for(char ch : ans) {
        cout << ch;
    }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while(T --) {
        solve();
    }
}