#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int bits=log2(n)+1;
        bool curBit=n&(1);
        cout<<"initial : "<<curBit<<endl;
        for(int i=1;i<bits;i++){
            cout<<"prev : "<<curBit<<" ";
            bool invertedBit=!curBit;
            cout<<"inverted : "<<invertedBit<<" ";
            bool idxBit=(n&(1<<i));
            cout<<"idxBit : "<<idxBit<<endl;
            if(invertedBit!=idxBit){
                return false;
            }
            curBit=!curBit;
        }
        return true;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Solution obj;
        cout<<obj.hasAlternatingBits(n)<<endl;
    }
}