#include<bits/stdc++.h>
using namespace std;

vector<int> addTwoArray(vector<int>a,vector<int>b){
    vector<int>result;
    int n=a.size();
    int carry=0;
    for(int i=n-1;i>=0;i--){
        int firstBit=a[i];
        int secondBit=b[i];
        int sum=(firstBit^secondBit^carry);
        result.push_back(sum);
        carry=(firstBit&secondBit)|(firstBit&carry)|(secondBit&carry);
    }
    if(carry){
        result.push_back(1);
    }
    reverse(result.begin(),result.end());
    return result;
}

int main(){
    vector<int>a={1,1,0,0,0,1,1};
    vector<int>b={0,0,0,0,0,1,0};
    vector<int>res=addTwoArray(a,b);
    for(auto it:res){
        cout<<it<<" ";
    }
    cout<<endl;
}