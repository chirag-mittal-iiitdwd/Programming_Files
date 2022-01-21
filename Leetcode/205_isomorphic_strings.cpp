#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>ms;
        unordered_map<char,char>mt;
        int n=s.size();

        for(int i=0;i<n;i++){
            if(ms[s[i]]==0 && mt[t[i]]==0){
                ms[s[i]]=t[i];
                mt[t[i]]=s[i];
            }
            else{
                if((ms[s[i]]!=t[i])||(mt[t[i]]!=s[i])){
                    return false;
                }
            }
        }
        return true;
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    char ch;
    if(ch==0){
        cout<<"yes\n";
    }
    else{
        cout<<"no\n";
    }
    return 0;
}