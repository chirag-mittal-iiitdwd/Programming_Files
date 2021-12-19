#include<bits/stdc++.h>
using namespace std;

// class Solution {
    // string repeat(int n,string s){
    //     string ans=s;
    //     for(int i=1;i<n;i++){
    //         s+=ans;
    //     }
    //     return s;
    // }

//     public:
//     string decodeString(string s) {
//         int n=s.size();
//         stack<int>num;
//         // stack<char>bracket;
//         stack<string>str;
//         int i=0;
//         while(i<n){
//             if(s[i]=='[' || s[i]==']'){
//                 // bracket.push(s[i]);
//                 i++;
//             }
//             else if(s[i]<='9' && s[i]>='0'){
//                 num.push(s[i]-'0');
//                 i++;
//             }
//             else{
//                 string cur{""};
//                 while(i<n && s[i]>='a' && s[i]<='z'){
//                     cur+=s[i];
//                     i++;
//                 }
//                 str.push(cur);
//             }
//         }

//         while(!num.empty()){
//             string x=str.top();
//             str.pop();
//             int n1=num.top();
//             num.pop();
//             str.push(repeat(n1,x));
//         }

//         return str.top();
//     }
// };

// class Solution {
// public:
//     string decodeString(const string& s, int& i) {
//         string res;
//         while(i<s.length() && s[i]!=']'){
//             if(isdigit(s[i])){
//                 int k=0;
//                 while(i<s.length() && isdigit(s[i])){
//                     k=k*10+s[i]-'0';
//                     i++;
//                 }
//                 i++; // Skipping the opening bracket
//                 string r=decodeString(s,i); // recursively getting the string which is between [ ] 
//                 while(k>0){
//                     res+=r; // Appending the string k times to answer
//                 }

//                 i++; // Skipping closing bracket
//             }
//             else{
//                 res+=s[i];
//                 i++;
            
//             }
//         }
//         return res;
//     }

//     string decodeString(string s) {
//         int i = 0;
//         return decodeString(s, i);
//     }
// };

class Solution {
public:
    string decodeString(const string& s, int& i) {
        string res;
        
        while (i < s.length() && s[i] != ']') {
            if (!isdigit(s[i]))
                res += s[i++];
            else {
                int n = 0;
                while (i < s.length() && isdigit(s[i]))
                    n = n * 10 + s[i++] - '0';
                    
                i++; // '['
                string t = decodeString(s, i);
                i++; // ']'
                
                while (n-- > 0)
                    res += t;
            }
        }
        
        return res;
    }

    string decodeString(string s) {
        int i = 0;
        return decodeString(s, i);
    }
};