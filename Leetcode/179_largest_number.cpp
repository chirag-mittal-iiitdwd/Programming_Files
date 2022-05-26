#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>mp;

        for(auto&it:nums){
            string temp=to_string(it);
            mp.push_back(temp);
        }

        sort(mp.begin(),mp.end(),[&](string&s1,string&s2){
            return s1+s2>s2+s1;
        });

        string ans="";
        for(auto&it:mp){
            ans+=it;
        }

        int iter=-1;
        for(int i=0;i<ans.length()-1;i++){
            if(ans[i]=='0'){
                iter++;
            }
            else{
                break;
            }
        }
        
        if(iter!=-1){
            iter++;
            ans=ans.substr(iter);
        }

        return ans;
    }
};