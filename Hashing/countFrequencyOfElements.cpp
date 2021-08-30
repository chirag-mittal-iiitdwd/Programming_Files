#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={2,2,2,1,1,4,3,4};
    map<int,int>mp;
    for(int i=0;i<8;i++){
        mp[arr[i]]++;
    }
    for(auto it:mp){
        cout<<it.first<<" "<<it.second<<endl;
    }
}