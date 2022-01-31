#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int inc=0,n=arr.size();
        if(n==1){
            return true;
        }
        for(int i=1;i<n;i++){
            if(arr[i-1]<arr[i]){
                inc++;
            }
            else{
                break;
            }
        }

        if(inc==0 || inc==n-1){
            return false;
        }

        for(int i=inc;i<n-1;i++){
            if(arr[i]<=arr[i+1]){
                return false;
            }
        }
        return true;
    } 
};