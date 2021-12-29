#include<bits/stdc++.h>
using namespace std;

class Solution { 
    void makeEqualLength(string&a,string&b){
        int n1=a.length();
        int n2=b.length();
        if(n1>n2){
            int diff=n1-n2;
            for(int i=0;i<diff;i++){
                b.insert(b.begin(),'0');
            }
        }
        else{
            int diff=n2-n1;
            for(int i=0;i<diff;i++){
                a.insert(a.begin(),'0');
            }
        }
    }
    public:
    string addBinary(string a, string b) {
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        string ans{""};
        if(a.length()!=b.length()){
            makeEqualLength(a,b);
        }

        int n=a.length();
        int carry=0;
        for(int i=n-1;i>=0;i--){
            if(a[i]=='1' && b[i]=='1'){
                if(carry==1){
                    ans+='1';
                }
                else{
                    ans+='0';
                    carry=1;
                }
            }
            else if(a[i]=='1' || b[i]=='1'){
                if(carry==1){
                    ans+='0';
                }
                else{
                    ans+='1';
                }
            }
            else{
                if(carry==1){
                    ans+='1';
                    carry=0;
                }
                else{
                    ans+='0';
                }
            }
        }
        if(carry!=0){
            ans+='1';
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

class Solution2{
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        string ret = "";
        bool carry = false;
        for(int i = 0; i < max(a.size(), b.size()); i++) {
            int anum = 0;
            int bnum = 0;
            if(i < a.size()) anum = a[i] - '0';
            if(i < b.size()) bnum = b[i] - '0';
            int num = anum + bnum;
            if(carry) num++;
            carry = (num>=2);
            num%=2;
           
            ret += '0' + num;
        }
        if(carry) ret += '1';
        reverse(ret.begin(), ret.end());
        return ret;
    }
};