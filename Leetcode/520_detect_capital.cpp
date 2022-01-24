#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007

class Solution {
public:
    bool detectCapitalUse(string s) {
        int n=s.length();
        bool cap=true;
        bool low=true;
        bool caplow=true;
        for(int i=0;i<n;i++){
            if(islower(s[i])){
                cap=false;
                if(i==0){
                    caplow=false;
                }
            }
            else{
                low=false;
                if(i!=0){
                    caplow=false;
                }
            }
        }
        return caplow||low||cap;
    }
};

class Solution {
public:
    bool detectCapitalUse(string s) {
        int n=s.length();
        bool firstCap=isupper(s[0]),allCap=true,alllow=true;
        for(int i=1;i<n;i++){
            if(isupper(s[i])){
                alllow=false;
            }
            else{
                allCap=false;
            }
        }
        return (firstCap&&allCap)||alllow;
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    return 0;
}