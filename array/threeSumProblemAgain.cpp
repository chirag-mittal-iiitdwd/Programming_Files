#include<bits/stdc++.h>
using namespace std;

/*
    Trying out all combinations
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(arr[i]+arr[j]+arr[k]==target){
                    found==true;
                }
            }
        }
    }
    
    Time Complexity : O(N^3)
*/

bool threeSumOptimised(vector<int>arr,int target){
    int n=arr.size();
    sort(arr.begin(),arr.end());

    // Fixing one of the variables with i
    for(int i=0;i<n;i++){

        // Problem Reduced to two pointer problem
        for(int j=i+1;j<n;j++){
            int lo=j,hi=n-1;
            while(lo<hi){
                if(arr[i]+arr[lo]+arr[hi]==target){
                    return true;
                }
                else if(arr[i]+arr[lo]+arr[hi]>target){
                    hi--;
                }
                else{
                    lo++;
                }
            }
        }
    }
    return false;
}
/*
    Time Complexity : O(N logN) + O(N^2)
    Space Complexity : O(1)
*/

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<threeSumOptimised(arr,k)<<endl;
}