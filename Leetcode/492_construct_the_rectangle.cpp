#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int>factors;
        for(int i=2;i*i<=area;i++){
            if((area%i)==0){
                factors.push_back(i);
            }
        }
        int n=factors.size();
        
        vector<int>ans;
        if((factors[n-1]*factors[n-1])==area){
            ans.push_back(factors[n-1]);
            ans.push_back(factors[n-1]);
        }
        else{
            ans.push_back(factors[n-2]);
            ans.push_back(area/factors[n-2]);
        }
        return ans;
    }
};