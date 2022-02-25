#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n=version1.length(),m=version2.length(),i=0,j=0;

        while(i<n || j<m){
            int s1=i,s2=j;

            while(i<n && version1[i]!='.'){
                i++;
            }
            int len1=i-s1;
            i++;
            
            while(j<m && version2[j]!='.'){
                j++;
            }
            int len2=j-s2;
            j++;

            int o=0,t=0;
            if((s1+len1)<n){
                o=stoi(version1.substr(s1,len1));
            }
            if((s2+len2)<m){
                t=stoi(version2.substr(s2,len2));
            }
            
            if(o!=t){
                if(o<t){
                    return -1;
                }
                else{
                    return 1;
                }
            }
        }
        return 0;
    }
};