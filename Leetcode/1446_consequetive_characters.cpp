#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPower(string s) {
        int current=1;
        char curCh=s[0];
        int n=s.size();
        int maxPwr=INT_MIN;
        for(int i=1;i<n;i++){
            if(curCh==s[i]){
                current++;
            }
            else{
                maxPwr=max(maxPwr,current);
                current=1;
                curCh=s[i];
            }
        }
        return maxPwr;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution obj;
        cout<<obj.maxPower(str)<<endl;
    }
}