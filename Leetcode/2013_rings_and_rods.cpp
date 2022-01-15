#include<bits/stdc++.h>
using namespace std;
#define int long long int

class Rod{
    public:
    int red=0;
    int green=0;
    int blue=0;
};

class Solution {
public:
    int countPoints(string rings) {
        int n=rings.length();
        vector<Rod>v(10);
        for(int i=0;i<n;i+=2){
            int idx=rings[i+1]-'0';
            if(rings[i]=='B'){
                v[idx].blue++;
            }
            else if(rings[i]=='G'){
                v[idx].green++;
            }
            else{
                v[idx].red++;
            }
        }

        int cnt=0;
        for(int i=0;i<=9;i++){
            if(v[i].green>0 && v[i].blue>0 && v[i].red>0){
                cnt++;
            }
        }
        return cnt;
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    return 0;
}