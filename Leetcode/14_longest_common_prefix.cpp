#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans{""};
        int n=strs.size();
        if(n==0){
            return ans;
        }
        int minInd=INT_MAX;
        string c=strs[0];
        for(int i=1;i<n;i++){
            int j=0,k=0;
            int count=0;
            while(j<c.size() && k<strs[i].size()){
                if(c[j]==strs[i][k]){
                    count++;
                }
                else{
                    break;
                }
                j++;
                k++;
            }
            minInd=min(minInd,count);
        }
        return c.substr(0,minInd);
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    vector<string>strs;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        strs.push_back(str);
    }
    Solution onj;
    cout<<onj.longestCommonPrefix(strs)<<endl;
}}