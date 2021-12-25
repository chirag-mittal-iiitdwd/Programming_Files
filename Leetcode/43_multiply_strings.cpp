#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int len1=num1.size();
        int len2=num2.size();
        vector<int>multi(len1+len2,0);

        int n1=0;
        int n2=0;
        for(int i=len1-1;i>=0;i--){
            int carry=0;
            n2=0;
            int first=num1[i]-'0';
            for(int j=len2-1;j>=0;j--){
                int sec=num2[j]-'0';
                int sum=first*sec+carry+multi[n1+n2];
                multi[n1+n2]=sum%10;
                carry=sum/10;
                n2++;
            }
            if(carry!=0){
                multi[n1+n2]=carry;
            }
            n1++;
        }

        string ans{""};
        bool flag=false;
        for(int i=len1+len2-1;i>=0;i--){
            if(multi[i]==0 && !flag){
                continue;
            }
            else{
                flag=true;
                ans+=to_string(multi[i]);
            }
        }

        return ans;
    }
};