#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int i=num.size()-1;

        int carry=0;
        while(i>-1 && k>0){
            int val=num[i]+k%10+carry;
            num[i]=val%10;
            carry=val/10;
            k/=10;
            i--;
        }


        if(k>0){
            int val=carry+k%10;
            k/=10;
            num.insert(num.begin(),val%10);
            carry/=10;
        }

        if(carry!=0){
            num.insert(num.begin(),carry);
        }
        return num;
    }
};