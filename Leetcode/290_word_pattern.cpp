#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n=pattern.size();
        int ns=s.size();
        unordered_map<char,string>mp;
        unordered_map<string,char>mp2;
        int sIter=0;
        
        for(int i=0;i<n;i++){
            string word{""};
            while(sIter<ns && s[sIter]!=' '){
                word+=s[sIter];
                sIter++;
            }
            sIter++;
            if(word==""){
                return false;
            }
            if(mp[pattern[i]]=="" && mp2[word]==0){
                mp[pattern[i]]=word;
                mp2[word]=pattern[i];
            }
            else{
                if((mp[pattern[i]]!=word)||(mp2[word]!=pattern[i])){
                    return false;
                }
            }
        }
        return true;
    }
};

class Solution{
    public:
    bool wordPattern(string pattern,string s){
        int n=pattern.size();
        int ns=s.size();

        queue<string>q;
        int sIter=0;
        while(sIter<ns){
            string word{""};
            while(sIter<ns && s[sIter]!=' '){
                word+=s[sIter];
                sIter++;
            }
            q.push(word);
            sIter++;
        }
        if(q.size()!=n){
            return false;
        }

        unordered_map<char,string>mp;
        unordered_map<string,char>mp2;
        for(int i=0;i<n;i++){
            string word=q.front();
            q.pop();
            if(mp[pattern[i]]=="" && mp2[word]==0){
                mp[pattern[i]]=word;
                mp2[word]=pattern[i];
            }
            else{
                if((mp[pattern[i]]!=word)||(mp2[word]!=pattern[i])){
                    return false;
                }
            }
        }
        if(!q.empty()){
            return false;
        }
        return true;
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    return 0;
}