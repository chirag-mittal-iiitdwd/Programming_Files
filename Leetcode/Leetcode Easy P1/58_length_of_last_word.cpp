#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        s+=' ';
        int n=s.length();
        int cur=0;
        int lastWord=0;
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                if(cur!=0){
                    lastWord=cur;
                }
                cur=0;
            }
            else{
                cur++;
            }
        }
        return lastWord;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    return 0;
}