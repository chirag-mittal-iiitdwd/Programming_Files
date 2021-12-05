#include<bits/stdc++.h>
using namespace std;
class Solution{
    string printSubStr(string str, int low, int high){
        string ans{""};
        for (int i = low; i <= high; ++i)
            ans+=str[i];
        return ans;
    }
    public:
    string longestPalindrome(string s){
        int n=s.length();
        bool t[n][n];
        memset(t,false,sizeof(t));

        // Marking the individual elements as true because they are palindromes
        int maxLen=1;
        for(int i=0;i<n;++i){
            t[i][i]=true;
        }

        // Checking for any substrings with length equal to 2
        int start=0;
        for(int i=0;i<n-1;++i){
            if(s[i]==s[i+1]){
                t[i][i+1]=true;
                start=i;
                maxLen=2;
            }
        }

        // Now checking for rest of the string cases and these will build upon alredy done work
        for(int k=3;k<=n;++k){
            for(int i=0;i<n-k+1;++i){
                int j=i+k-1;
                if(t[i+1][j-1] && s[i]==s[j]){
                    t[i][j]=true;
                    if(k>maxLen){
                        start=i;
                        maxLen=k;
                    }
                }
            }
        }
        return printSubStr(s,start,start+maxLen-1);
    }
};

int main(){
    string str;
    cin>>str;
    Solution obj;
    cout<<obj.longestPalindrome(str)<<endl;
}