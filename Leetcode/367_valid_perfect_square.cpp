#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        for(int i=2;i*i<=num;i++){
            int cnt=0;
            while((num%i)==0){
                num/=i;
                cnt++;
            }
            if(cnt&1){
                return false;
            }
        }
        if(num>1){
            return false;
        }
        return true;
    }
};