#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>ans={};
        int n=digits.length();
        if(n==0){
            return ans;
        }
        vector<string>letter={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string firstKeyLetters=letter[digits[0]-'0'-2];
        for(int i=0;i<firstKeyLetters.length();i++){
            string x{""};
            x+=firstKeyLetters[i];
            ans.push_back(x);
        }
        if(n==1){
            return ans;
        }
        for(int i=1;i<n;i++){
            string keyString=letter[digits[i]-'0'-2];
            vector<string>temp=ans;
            ans.clear();
            for(int j=0;j<temp.size();j++){
                for(int k=0;k<keyString.length();k++){
                    string str{""};
                    str.append(temp[j]);
                    str+=keyString[k];
                    ans.push_back(str);
                }
            }
        }
        return ans;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution obj;
        vector<string>ans=obj.letterCombinations(str);
        for(auto &it:ans){
            cout<<it<<endl;
        }
    }
}