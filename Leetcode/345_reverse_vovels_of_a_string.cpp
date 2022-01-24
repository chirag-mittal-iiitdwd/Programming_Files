#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007

class Solution {
    bool isVovel(char s){
        if(s=='a' || s=='e' || s=='i' || s=='o' || s=='u'){
            return true;
        }
        return false;
    }
public:
    string reverseVowels(string s) {
        vector<char>v;
        for(auto &it:s){
            if(isVovel(it)){
                v.push_back(it);
            }
        }
        int i=v.size()-1;
        for(auto &it:s){
            if(isVovel(it)){
                it=v[i];
                i--;
            }
        }
        return s;
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    return 0;
}