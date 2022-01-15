#include<bits/stdc++.h>
using namespace std;
// #define int long long int
#define ll long long int

class Solution {
    void removeSpaces(string&s){
        int n=s.length();
        int i=0;
        for(i=0;i<n;i++){
            if(s[i]!=' '){
                break;
            }
        }
        s=s.substr(i,n);
    }
    bool isNeg(string&s){
        int n=s.length();
        bool flag=false;
        if(s[0]=='-'){
            s=s.substr(1,n);
            flag=true;
        }
        else if(s[0]=='+'){
            s=s.substr(1,n);
        }
        return flag;
    }
    public:
    int myAtoi(string s) {
        removeSpaces(s);
        bool flag=isNeg(s);
        int n=s.length();
        string ans{""};
        for(int i=0;i<n;i++){
            if(s[i]>='0' && s[i]<='9'){
                ans.push_back(s[i]);
            }
            else{
                break;
            }
        }
        if(ans.length()>0){
            try{
                ll ans1=stoi(ans);
                if(flag){
                    ans1=-ans1;
                }
                return ans1;
            }
            catch(std::out_of_range &e){
                if(flag){
                    return INT_MIN;
                }
                else{
                    return INT_MAX;
                }
            }
        }
        else{
            return 0;
        }
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    return 0;
}