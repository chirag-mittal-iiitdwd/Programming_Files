#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximum69Number (int num) {
        int ans=0;
        stack<int>st;
        int pwr10=1;

        while(num>0){
            int rem=num%10;
            num/=10;
            st.push(rem);
            pwr10*=10;
        }

        bool flag=false;
        while(!st.empty()){
            if(!flag && st.top()==6){
                ans+=(pwr10*9);
                flag=true;
            }
            else{
                ans+=(pwr10*st.top());
            }
            pwr10/=10;
            st.pop();
        }

        return ans;
    }
};