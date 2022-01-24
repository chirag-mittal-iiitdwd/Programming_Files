#include<bits/stdc++.h>
using namespace std;

class Solution {
    // void findStarting(int&lowDigits,int&low,vector<int>&ans,int&high){
    //     string ans{};
    //     int numsPossible=10-lowDigits;
        
    //     for(int i=0;i<numsPossible;i++){
    //         string cur{""};
    //         for(int j=i+1;j<lowDigits+i+1;j++){
    //             cur+=((char)48+j);
    //         }
    //         int num=stoi(cur);
    //         if(num>=low && num<=high){
    //             ans.push_back(num);
    //         }
    //     }
    // }
public:
    vector<int> sequentialDigits(int low, int high) {
        string num="123456789";
        vector<int>ans;
        int lowDigits=log10(low)+1;
        int highDigits=log10(high)+1;

        for(int len=lowDigits;len<=highDigits;len++){
            int numsPossible=10-len;
            for(int i=0;i<numsPossible;i++){
                int x=stoi(num.substr(i,len));
                if(x>=low && x<=high){
                    ans.push_back(x);
                }
                else if(x>high){
                    break;
                }
            }
        }
        return ans;
    }
};