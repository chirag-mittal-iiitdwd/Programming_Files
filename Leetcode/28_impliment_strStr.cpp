#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()==0){
            return 0;
        }
        
        int n=haystack.size(),i=0;

        while(i<n){
            if(haystack[i]==needle[0]){
                int start=i;
                for(int j=0;j<needle.size();j++){
                    if(i<n && needle[j]==haystack[j]){
                        i++;
                        j++;
                    }
                    else{
                        break;
                    }
                }
                if(start+needle.size()==i){
                    return start;
                }
            }
            i++;
        }

        return -1;
    }
};