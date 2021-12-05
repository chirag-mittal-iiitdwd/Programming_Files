#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int lengthOfLongestSubstring(string s){
        int n=s.length();
        int res=0;
        vector<int>lastIDX(256,-1);
        int i=0;
        for(int j=0;j<n;j++){
            i=max(i,lastIDX[s[j]]+1);
            res=max(res,j-i+1);
            lastIDX[s[j]]=j;
        }
        return res;
    }
};


int main(){
    string str;
    cin>>str;
    Solution onj;
    cout<<onj.lengthOfLongestSubstring(str)<<endl;
}