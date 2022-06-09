#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long xorT=0;
        for(auto&it:nums){
            xorT^=it;
        }

        long setBitPos=xorT&~(xorT-1);

        long xor1=0,xor2=0;
        for(auto&it:nums){
            if(it&setBitPos){
                xor1^=it;
            }
            else{
                xor2^=it;
            }
        }

        return {(int)xor1,(int)xor2};
    }
};

int main(){
    int x=((16)&(-16));
    cout<<x<<endl;
    cout<<((16)&(-16))<<endl;
}