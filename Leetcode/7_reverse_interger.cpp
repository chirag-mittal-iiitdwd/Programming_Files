#include<bits/stdc++.h>
using namespace std;
#define ll long long int
class Solution{
    int reverseNumber(int x){
        bool isNeg=false;
        if(x<0){
            x=abs(x);
            isNeg=true;
        }
        int ans{0};
        while(x>0){
            int temp=x%10;
            ans*=10;
            ans+=temp;
            x/=10;
        }
        if(isNeg){
            ans=-ans;
        }
        if(ans<INT_MIN || ans>INT_MAX){
            return 0;
        }   
        return ans;
    }
    public: 
    int reverse(int x){
        return reverseNumber(x);
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        Solution obj;
        cout<<obj.reverse(x)<<endl;
    }
}