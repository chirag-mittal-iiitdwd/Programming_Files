#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n=word.size();
        int idx=find(word.begin(),word.end(),ch)-word.begin();
        if(idx==n){
            return word;
        }

        
    }
};