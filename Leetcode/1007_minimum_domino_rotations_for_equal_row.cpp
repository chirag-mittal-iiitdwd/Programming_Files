#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n=tops.size();

        vector<int>top(7,0);
        vector<int>bottom(7,0);
        vector<int>same(7,0);

        for(int i=0;i<n;i++){
            top[tops[i]]++;
            bottom[bottoms[i]]++;
            if(tops[i]==bottoms[i]){
                same[tops[i]]++;
            }
        }

        for(int i=1;i<=6;i++){
            if(top[i]+bottom[i]-same[i]==n){
                return min(top[i],bottom[i]);
            }
        }

        return -1;
    }
};