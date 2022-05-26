#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     string reverseWords(string s) {
//         string word="";
//         s+=' ';
//         int n=s.length();

//         stack<string>st;
//         for(int i=0;i<n;i++){
//             if(s[i]==' ' && word.length()==0){
//                 continue;
//             }
//             else if(s[i]==' ' && word.length()!=0){
//                 st.push(word);
//                 word="";
//             }
//             else{
//                 word+=s[i];
//             }
//         }

//         string ans="";
//         while(!st.empty()){
//             ans+=st.top();
//             ans+=' ';
//             st.pop();
//         }
//         ans.pop_back();
//         return ans;
//     }
// };

class Solution {
public:
    string reverseWords(string s) {
        s=' '+s;
        string word="";

        int n=s.size();
        for(int i=n-1;i>=0;i--){
            if(s[i]==' ' && word.length()==0){
                continue;
            }
            else if(s[i]==' ' && word.length()!=0){
                reverse(word.begin(),word.end());
                s+=word;
                s+=' ';
                word="";
            }
            else{
                word+=s[i];
            }
        }
        s.pop_back();
        return s.substr(n);
    }
};