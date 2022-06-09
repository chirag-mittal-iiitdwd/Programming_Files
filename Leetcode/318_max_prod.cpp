#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();

        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                bool flag=true;
                for(int k=0;k<words[i].size();k++){
                    if(find(words[j].begin(),words[j].end(),words[i][k])!=words[j].end()){
                        flag=false;
                        break;
                    }
                }

                if(flag){
                    ans=max(ans,((int)(words[j].size()*words[i].size())));
                }
            }
        }

        return ans;
    }
};


class Solution {
    int getState(string&str){
        int state=0;
        for(auto&it:str){
            int idx=it-'a';
            state|=1<<idx;
        }
        return state;
    }
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
        vector<int>state(n);

        for(int i=0;i<n;i++){
            state[i]=getState(words[i]);
        }

        int maxProd=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((state[i]&state[j])==0){
                    maxProd=max(maxProd,((int)(words[j].size()*words[i].size())));
                }
            }
        }

        return maxProd;
    }
};