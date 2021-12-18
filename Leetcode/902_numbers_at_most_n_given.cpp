#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        string NS = to_string(N);
        int digit = NS.size(), dsize = D.size(), rtn = 0;
        
        for (int i = 1 ; i < digit ; ++i)
            rtn += pow(dsize, i);
        
        for (int i = 0 ; i < digit ; ++i) {
            bool hasSameNum = false;
            for (string &d : D) {
                if (d[0] < NS[i]) 
                    rtn += pow(dsize, digit - i - 1);
                else if (d[0] == NS[i]) 
                    hasSameNum = true;
            }
            if (!hasSameNum) return rtn;
        }               
        return rtn+1;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        vector<string>str(n);
        for(int i=0;i<n;i++){
            cin>>str[i];
        }
        Solution obj;
        cout<<obj.atMostNGivenDigitSet(str,x)<<endl;
        cout<<endl;
    }
}