#include<bits/stdc++.h>
using namespace std;

class Solution {
    int calcSq(int n){
        int ans=0;
        while(n>0){
            int last=n%10;
            ans+=(last*last);
            n/=10;
        }
        return ans;
    }
public:
    bool isHappy(int n) {
        if(n==1){
            return true;
        }
        unordered_map<int,bool>mp;
        while(mp[n]==false){
            mp[n]=true;
            n=calcSq(n);
            if(n==1){
                return true;
            }
        }
        return false;
    }
};


class Solution {
public:
    bool isHappy(int n) {
        
        if (n == 1 || n == 7)
            return true;
        
        int sum = n;        
        while(sum > 9){            
            sum=0;
            
            while(n>0){
                int ld = n%10;            
                sum += ld*ld;            
                n /= 10;
            }           
            if(sum==1)
                return true;
            n = sum;
        }       
        if(sum == 7)
            return true;
        return false;
    }
};