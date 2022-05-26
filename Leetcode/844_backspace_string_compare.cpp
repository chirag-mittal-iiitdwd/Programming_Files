#include<bits/stdc++.h>
using namespace std;

class Solution {
    string removeSpaces(string str){
        int n=str.length();

        int spaceCnt=0;
        for(int i=n-1;i>=0;i--){
            if(str[i]=='#'){
                spaceCnt++;
            }
            else if(str[i]!='#' && spaceCnt==0){
                continue;
            }
            else{
                spaceCnt--;
                str[i]='#';
            }
        }

        int j;
        for(int i=j=0;i<n;i++){
            if(str[i]!='#'){
                str[j++]=str[i];
            }
        }

        str=str.substr(0,j);

        return str;
    }
public:
    bool backspaceCompare(string s, string t) {
        return removeSpaces(s)==removeSpaces(t);
    }
};