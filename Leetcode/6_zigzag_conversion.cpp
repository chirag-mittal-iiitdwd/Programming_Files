#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<=1){
            return s;
        }
        vector<vector<char>>x(numRows);
        int n=s.length();
        int row=0;
        bool down=true;
        for(int i=0;i<n;i++){
            x[row].push_back(s[i]);
            if(row==numRows-1){
                down=false;
            }
            else if(row==0){
                down=true;
            }
            if(down==true){
                row++;
            }
            else{
                row--;
            }
        }
        string ans{""};
        for(int i=0;i<numRows;i++){
            for(auto &it:x[i]){
                cout<<it<<" ";
                ans+=it;
            }
            cout<<endl;
        }
        return ans;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
    int n;
    string str;
    cin>>str;
    cin>>n;
    Solution obj;
    cout<<obj.convert(str,n)<<endl;
    cout<<endl;
}}