#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int guessNumber(int n) {
        int l=1,r=n;
        while(l<=n){
            int mid=(l-((l-r)/2));
            if(guess(mid)==0){
                return mid;
            }
            else if(guess(mid)==-1){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return 0;
    }
};