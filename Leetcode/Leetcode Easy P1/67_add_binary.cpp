#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int n=a.length(),m=b.length(),carry=0,i=0,j=0;

        string ans{""};
        while(i<n || j<m){
            int sum=0;
            if(i<n){
                sum+=a[i]-'0';
            }
            if(j<m){
                sum+=b[j]-'0';
            }
            sum+=carry;
            carry=sum/2;
            ans+=to_string(sum%2);
        }
        if(carry!=0){
            ans+=to_string(carry);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main(){
    
}