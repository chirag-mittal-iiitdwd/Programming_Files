#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string getBinary(int n){
        string ans;
        for(int i=1<<30;i>0;i=i/2){
            if(n&i){
                ans+="1";
            }
            else{
                ans+="0";
            }
        }
        return ans;
    }
};



int main(){
    int n;
    cin>>n;
    Solution o;
    cout<<o.getBinary(n)<<endl;
}