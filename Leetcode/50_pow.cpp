#include<bits/stdc++.h>
using namespace std;

class Solution {
    double helper(double x,long long int n,int flag){
        double ans=1;

        while(n){
            if(n&1){
                if(flag==-1){
                    ans/=x;
                }
                else{
                    ans*=x;
                }
                n--;
            }
            else{
                x=x*x;
                n/=2;
            }
        }
        return ans;
    }
public:
    double myPow(double x, int n) {
        n=(long long)
        if(n<0){
            return helper(x,-n,-1);
        }
        else{
            return helper(x,n,1);
        }
    }
};