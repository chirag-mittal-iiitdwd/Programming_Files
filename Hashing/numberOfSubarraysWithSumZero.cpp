/*
    Compute prefix sum
    prefix sum is the sum till ith element
    if lets suppose some value is x (index i) in the array and again that vale comes at index (j)
    now this means that there was some chemical locha in between due to which the sum
    became zero

    now the sum of i+1 th element to j will be zero
    If we compute how many times x has incurred in the array
    and choose two at a time in MC2
    and if the key is zero than we also have to include it because zero is what we want as answer

    1. Map prefix sum to a map
    2. For every key, choose 2 values from all the occurances of 
       particular prefsum (MC2)
    3. Speacial Case : for prefsum 0, we have to also include them
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=4;
    int arr[n]={1,-1,1,-1};
    map<int,int>cnt;

    int prefSum=0;
    for(int i=0;i<n;i++){
        prefSum+=arr[i];
        cnt[prefSum]++;
    }
    for(auto it:cnt){
        cout<<it.first<<" "<<it.second<<endl;
    }

    int ans=0;
    map<int,int>::iterator it;
    for(it=cnt.begin();it!=cnt.end();it++){
        int c=it->second;
        ans+=c*(c-1)/2;
        if(it->first==0){
            ans+=it->second;
        }

    }
    cout<<ans<<endl;
}