#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int start=0,end=x;
        int ans=0;
        while(start<=end){
            int mid=(start+((end-start)/2));
            int midSq=mid*mid;
            if(midSq==x){
                ans=mid;
                return;
            }
            else if(midSq<x){
                start=mid+1;
                ans=mid;
            }
            else{
                end=mid-1;
            }
        }
        return ans;
    }
};