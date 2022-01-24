#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int addDigits(int n) {
        while(n>9){
            int num=0;
            while(n){
                num+=n%10;
                n/=10;
            }
            n=num;
        }
        return n;
    }
};

class Solution {
public:
    int addDigits(int n) {
        return (1+((n-1)%9));
    }
};