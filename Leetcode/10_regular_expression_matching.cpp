#include<bits/stdc++.h>
using namespace std;

// s = the actual string
// p = pattern

// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         int ns=s.size();
//         int np=p.size();
//         bool t[np][ns];
//         memset(t,-1,sizeof(t));

//         /*
//             Base cases :
//             Empty string can match with, Empty pattern  ---> t[0][0]=true;
//             For the row, meaning for the base cases of the string, 
//                 everything will be false because empty pattern cannot match with any
//                 string except and for NULL string we made t[0][0] as true
            
//             For the column, meaning for the base case of the pattern,
//                 everything will be false except for the * characters, because an empty string cannot match with only NULL pattern
//                 for * we need to check more things, we will check the value at t[i-2][0] and copy it to the * ,
//                 because empty string can match with the pattern when it is for the form .* the * will make itself NULL character and thus making the . also NULL
//                 which will now match with the NULL string 
//         */
//         t[0][0]=true;
//         for(int i=1;i<=ns;i++){
//             t[0][i]=false;
//         }
//         for(int i=1;i<=np;i++){
//             if(p[i]!='*'){
//                 t[i][0]=false;
//             }
//             else{
//                 // cout<<t[i-1][0]<<endl;
//                 t[i][0]=t[i-1][0];
//             }
//         }

//         /*
//             Main Logic :
//             If the character in the string matches with the character in the pattern then we just copy the value at t[i-1][j-1] this will make sure that the previous strings matches with the string
//             If the character in the pattern is . then again simply copy t[i-1][j-1] because this can make any character out of itself and match with string's current char and like in previous we need to make sure that our string previous to this satisfies the pattern
//             If the patterns current character is a * then and pattern[i-1] matches with string[j] then the t[i][j] = t[i-2][j] || t[i-1][j],
//                 why we did this, t[i-2][j] represents the condition when the * in patterns makes itself nothing
//                 and t[i-1][j] represents the condition when the * has made itself a character and it maches with the char at string, and why we stopped at two only that is because going any further will increase the pattern size and two unequal strings cannot be equal, sometimes the size of string larger than pattern is acceptable because it has capacity to expand and contract itself
//         */

//         for(int i=1;i<=np;i++){
//             for(int j=1;j<=ns;j++){
//                 if(p[i-1]==s[j-1] || p[i-1]=='.'){
//                     t[i][j]=t[i-1][j-1];
//                 }
//                 else{
//                     if(p[i-1]=='*' && p[i-2]==s[j-1]){
//                         t[i][j]=t[i][j-1]||t[i-2][j];
//                     }
//                     else{
//                         t[i][j]=t[i-2][j];
//                     }
//                 }
//             }
//         }

//         // for(int i=0;i<=np;i++){
//         //     for(int j=0;j<=ns;j++){
//         //         cout<<t[i][j]<<" ";
//         //     }
//         //     cout<<endl;
//         // }
//         // cout<<endl;
//         return t[np][ns];
//     }
// };

class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=0;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i==0){
				//if i=0 ,then dp[i][j]=1 if we are be able make p[0,j] of 0 length
                    if(p[j-1]=='*'){
                        dp[i][j]|=dp[i][j-2];
                    }
                }
                else{
                    if(s[i-1]==p[j-1] || p[j-1]=='.'){
                        dp[i][j]|=dp[i-1][j-1];
                    }
                    if(p[j-1]=='*'){
                         dp[i][j]|=dp[i][j-2];// if we take 0 times  preceding element  
                        if(s[i-1]==p[j-2] || p[j-2]=='.')dp[i][j]|=dp[i-1][j];
                    }
                }
            }
        }
        return dp[n][m];
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        string s,p;
        cin>>s>>p;
        Solution obj;
        cout<<obj.isMatch(s,p)<<endl;
    }
}