#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int>mp2;
        int n=list1.size(),m=list2.size(),idxSum=INT_MAX;;

        for(int i=0;i<m;i++){
            mp2[list2[i]]=i+1;
        }

        int idxIn2=0,sum=0;
        for(int i=0;i<n;i++){
            idxIn2=mp2[list1[i]];
            if(idxIn2!=0){
                sum=(i+1)+(idxIn2);

                if(sum<idxSum){
                    idxSum=sum;
                }
            }
        }

        vector<string>ans;
        for(int i=0;i<n;i++){
            idxIn2=mp2[list1[i]];
            if(idxIn2!=0){
                sum=(i+1)+(idxIn2);
                if(sum==idxSum){
                    ans.push_back(list1[i]);
                }
            }
        }
        return ans;
    }
};