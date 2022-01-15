#include<bits/stdc++.h>
using namespace std;
#define int long long int

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        ios_base::sync_with_stdio(false);
        int n=bills.size();
        int fr=0,tn=0,tw=0;
        for(int i=0;i<n;i++){
            if(bills[i]==5){
                fr++;
            }
            else if(bills[i]==10){
                if(fr!=0){
                    fr--;
                    tn++;
                }
                else{
                    return false;
                }
            }
            else{
                if(tn!=0 && fr!=0){
                    tn--;
                    fr--;
                    tw++;
                }
                else if(fr>=3){
                    tw++;
                    fr-=3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    return 0;
}