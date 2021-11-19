#include<bits/stdc++.h>
using namespace std;

unordered_map<string,bool>mp;

class Solution{
    public:
    bool scrambledString(string a,string b){
        if(a.compare(b)==0){
            return true;
        }
        if(a.length()<=1 || b.length()<=1){
            return false;
        }
        string key=a+'_'+b;
        if(mp.find(key)!=mp.end()){
            return mp[key];
        }
        int n=a.length();
        bool flag=false;
        for(int i=1;i<n;i++){
            if(scrambledString(a.substr(0,i),b.substr(n-i,i))&&scrambledString(a.substr(i,n-i),b.substr(0,n-i))){
                flag=true;
                break;
            }
            else if(scrambledString(a.substr(0,i),b.substr(0,i))&&scrambledString(a.substr(i,n-i),b.substr(i,n-i))){
                flag=true;
                break;
            }
        }
        mp[key]=flag;
        return flag;
    }
};

int main(){
    string a,b;
    cin>>a>>b;
    Solution obj;
    cout<<obj.scrambledString(a,b)<<endl;
}