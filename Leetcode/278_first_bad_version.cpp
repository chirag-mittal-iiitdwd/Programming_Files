#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstBadVersion(int n) {
        int l=1,r=n;
        while(l<r){
            int mid=(l-((l-r)/2));
            if(!isBadVersion(mid)){
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
        return l;
    }
};