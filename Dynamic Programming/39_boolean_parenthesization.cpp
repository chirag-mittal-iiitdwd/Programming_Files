/*
    The string can only be made from { T , F , & , | , ^ }
    We have to insert brackets such that the value of the expression turns out to be true
    We have to find number of such ways

    the value of K must be increased by 2 units

    i = 0 and j = str.length()-1 will work here

    if( i > j ) return false
    if( i == j ){
        if(isTrue) return s[i]==T
    }
    else return s[i]==F

    loop i=k+1 to k=j-1 k+=2 {
        int leftT=solve(s,i,k-1,T)
        int leftF=solve(s,i,k-1,F)
        int rightT=solve(s,k+1,j,T)
        int rightF=solve(s,k+1,j,F)

        if(s[k]=='&'){
            if(isTrue==True){
                ans+=(leftT*rightT)
            }
            else{
                ans+=(lf*rt + lf*rf * lf*rf)
            }
        }
        else if(s[k]=='|'){
            if(isTrue==True){
                ans+=(lf*rt + lt*rf + lt*rt)
            }
            else{
                ans+=(lf*rf)
            }
        }
        else{
            if(isTrue==True){
                ans+=(lt*rf + lf*rt)
            }
            else{
                ans+=(lt*rt + lf*rf)
            }
        }
    }
    return ans
*/

#include<bits/stdc++.h>
using namespace std;

int solve(string s,int i,int j,int isTrue){
    if(i>j){
        return 0;
    }
    if(i==j){
        if(isTrue==1){
            return s[i]=='T';
        }else{
            return s[i]=='F';
        }
    }
    int ans=0;
    for(int k=i+1;k<=j-1;k=k+2){
        int leftT=solve(s,i,k-1,1);
        int leftF=solve(s,i,k-1,0);
        int rightT=solve(s,k+1,j,1);
        int rightF=solve(s,k+1,j,0);
        if(s[k]=='&'){
            if(isTrue==1){
                ans+=(leftT*rightT);
            }
            else{
                ans+=(leftF*rightT + leftF*rightF + leftT*rightF);
            }
        }
        else if(s[k]=='|'){
            if(isTrue==1){
                ans+=(leftF*rightT + leftT*rightF + leftT*rightT);
            }
            else{
                ans+=(leftF*rightF);
            }
        }
        else if(s[k]=='^'){
            if(isTrue==1){
                ans+=(leftT*rightF + leftF*rightT);
            }
            else{
                ans+=(leftT*rightT + leftF*rightF);
            }
        }
    }
    return ans;
}

int main(){
    string str="T|T&F^T";
    cout<<solve(str,0,str.length()-1,1);
}

// #include <bits/stdc++.h>
// using namespace std;

// int dp[101][101][2];
// int parenthesis_count(string s,int i,int j, int isTrue){
//     if (i > j)
//         return false;
//     if (i == j)
//     {
//         if (isTrue == 1)
//             return s[i] == 'T';
//         else
//             return s[i] == 'F';
//     }

//     if (dp[i][j][isTrue] != -1)
//         return dp[i][j][isTrue];
//     int ans = 0;
//     for (int k = i + 1; k <= j - 1; k = k + 2)
//     {
//         int leftF, leftT, rightT, rightF;
//         if (dp[i][k - 1][1] == -1)
//         {
//             leftT = parenthesis_count(s, i, k - 1, 1);
//         } // Count no. of T in left partition
//         else
//         {
//             leftT = dp[i][k - 1][1];
//         }

//         if (dp[k + 1][j][1] == -1)
//         {
//             rightT = parenthesis_count(s, k + 1, j, 1);
//         } // Count no. of T in right partition
//         else
//         {
//             rightT = dp[k + 1][j][1];
//         }

//         if (dp[i][k - 1][0] == -1)
//         {
//             // Count no. of F in left partition
//             leftF = parenthesis_count(s, i, k - 1, 0);
//         }
//         else
//         {
//             leftF = dp[i][k - 1][0];
//         }

//         if (dp[k + 1][j][0] == -1)
//         {
//             // Count no. of F in right partition
//             rightF = parenthesis_count(s, k + 1, j, 0);
//         }
//         else
//         {
//             rightF = dp[k + 1][j][0];
//         }

//         if (s[k] == '&')
//         {
//             if (isTrue == 1)
//                 ans += leftT * rightT;
//             else
//                 ans += leftF * rightF + leftT * rightF + leftF * rightT;
//         }
//         else if (s[k] == '|')
//         {
//             if (isTrue == 1)
//                 ans += leftT * rightT + leftT * rightF + leftF * rightT;
//             else
//                 ans = ans + leftF * rightF;
//         }
//         else if (s[k] == '^')
//         {
//             if (isTrue == 1)
//                 ans = ans + leftF * rightT + leftT * rightF;
//             else
//                 ans = ans + leftT * rightT + leftF * rightF;
//         }
//         dp[i][j][isTrue] = ans;
//     }
//     return ans;
// }

// // Driver Code
// int main()
// {
//     string symbols = "TTFT";
//     string operators = "|&^";
//     string s;
//     int j = 0;

//     for (int i = 0; i < symbols.length(); i++)
//     {
//         s.push_back(symbols[i]);
//         if (j < operators.length())
//             s.push_back(operators[j++]);
//     }

//     // We obtain the string  T|T&F^T
//     int n = s.length();

//     // There are 4 ways
//     // ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) and
//     // (T|((T&F)^T))
//     memset(dp, -1, sizeof(dp));
//     cout << parenthesis_count(s, 0, n - 1, 1);
//     return 0;
// }