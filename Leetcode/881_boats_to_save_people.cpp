#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int l=0,r=people.size()-1;

        int boats=0;
        while(l<=r){
            int cur=0;

            if(people[r]+people[l]<=limit){
                l++;
                r--;
            }
            else{
                r--;
            }
            boats++;
        }

        return boats;
    }
};