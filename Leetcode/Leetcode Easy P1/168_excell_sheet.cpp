#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string ans{""};
        int bits=(log2(n)/log2(26))+1;
        while(bits--){
            int power=pow(26,bits);
            cout<<"power : "<<power;
            int div=n/power;
            cout<<"div : "<<div;
            ans+=((char)64+div);
            n-=(power*div);
            cout<<"changes n: "<<n<<endl;
        }
        return ans;
    }
};

int main(){
    int n;
    cin>>n;
    Solution obj;
    cout<<obj.convertToTitle(n)<<endl;
    return 0;
}