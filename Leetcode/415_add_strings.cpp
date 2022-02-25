#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());

        int carry=0,i=0,j=0,n=num1.size(),m=num2.size();
        string ans={""};
        while(i<n || j<m){
            int first=0,second=0;
            if(i<n){
                first=num1[i]-'0';
                i++;
            }
            if(j<m){
                second=num2[j]-'0';
                j++;
            }
            int sum=first+second+carry;
            int rem=sum%10;
            carry=sum/10;
            ans+=to_string(rem);
        }
        if(carry!=0){
            ans+=to_string(carry);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};