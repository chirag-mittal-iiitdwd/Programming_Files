#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while (t--){
        ll n;
        cin >> n;
        string s, p;
        cin >> s >> p;
        bool is_same = true;
        for(int i = 0; i < n; i++){
            if(s[i] != p[i]){
                is_same = false;
                break;
            }
        }
        if(is_same){
            cout << "YES" << endl;
            continue;
        }

        ll cc0 = 0, cc1 = 0;
        for(auto x: p){
            if(x == '1'){
                cc1++;
            }else{
                cc0++;
            }
        }

        if(cc1 > 0 && cc0 > 0){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}