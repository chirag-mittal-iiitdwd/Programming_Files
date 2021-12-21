#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=INT_MIN || n>=INT_MAX){
            return false;
        }
        if(n==0){
            return false;
        }
        long long int x=(((long long int)n)&((long long int)n-1));
        if(x==0){
            return true;
        }
        else{
            return false;
        }
    }
};