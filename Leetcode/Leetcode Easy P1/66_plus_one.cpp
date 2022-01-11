#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int i=n-1;
        if(digits[n-1]==9){
            while(i>=0){
                if(digits[i]==9){
                    digits[i]=0;
                    i--;
                }
                else{
                    break;
                }
            }
            if(i>=0){
                digits[i]++;
            }
            else{
                digits.insert(digits.begin(),1);
            }
        }
        else{
            digits[n-1]++;
        }
        return digits;
    }
};