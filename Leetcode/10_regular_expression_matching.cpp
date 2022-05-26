#include<bits/stdc++.h>
using namespace std;

// class Solution{
//     bool helper(string&s,string&p,int n,int m){
//         if(n==-1 && m==-1){
//             return true;
//         }
//         if(m==-1){
//             return false;
//         }

//         if(n==-1){
//             if(p[m]=='*'){
//                 return helper(s,p,n,m-2);
//             }
//         }

//         if(s[n]==p[m] || p[m]=='.'){
//             return helper(s,p,n-1,m-1);
//         }

//         if(p[m]=='*'){
//             bool result=false;
//             if(s[n]==p[m-1] || p[m-1]=='.'){
//                 result = helper(s,p,n-1,m);
//             }
//             if(!result){
//                 result|=helper(s,p,n,m-2);
//             }
//             return result;
//         }
//         return false;
//     }
// public:
//     bool isMatch(string s, string p){
//         return helper(s,p,s.size()-1,p.size()-1);
//     }
// };


class Solution {
    bool helper(string s,string p,int i,int j){
        if(i==0 && j==0){
            return true;
        }
        if(j==0 || (i==0 && p[j]!='*')){
            return false;
        }

        if(i==0 && p[j]=='*'){
            return helper(s,p,i,j-2);
        }

        if(s[i]==p[j] || p[j]=='.'){
            return helper(s,p,i-1,j-1);
        }

        if(p[j]=='*'){
            bool result=false;
            if(s[i]==p[i-1] || p[i-1]=='.'){
                result=helper(s,p,i-1,j);
            }
            if(!result){
                result|=helper(s,p,i,j-2);
            }
            return result;
        }
        return false;
    }
public:
    bool isMatch(string s, string p) {
        return helper(s,p,s.size()-1,p.size()-1);
    }
};