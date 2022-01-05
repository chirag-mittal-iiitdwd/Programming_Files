#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution {
public:
    int bitwiseComplement(int n) {
        string bin{""};
        int ans=0;
        int i=0;
        int loop=log2(n)+1;
        while(i<n){
            int x=n&(i<<i);
            if(x==0){
                ans+=pow(2,i);
            }
            i++;
        }
        return ans;
    }
};

int main(){
    
    return 0;
}