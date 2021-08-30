/*
    For a given array and an integer K, check if any subarray such that
    elements in the subarray form a number divisible by 3

    ---> Approach 1
        Compute the numbers formed by all possible subarrays of size K.
        Check for their divisiblity with 3

        Time Complexity = O(n^2)
    ---> Approach 2
        Sum of initial K elements from the array
        Use sliding window technique and one by one, start subtracting
        elements from the end and adding from the end
        At each step, check if sum divisible by 3 or not. If it is, print
        the elements

        Time Complexity = O(n)
*/

#include<iostream>
#include<vector>
using namespace std;

void computeNumber(vector<int> arr,int k){
    pair<int,int> ans;
    int sum=0;
    for(int i=0;i<k;i++){
        sum+=arr[i];
    }
    bool found=false;
    if(sum%3==0){
        ans=make_pair(0,k-1);
        found=true;
    }

    for(int i=k;i<arr.size();i++){
        if(found){
            break;
        }
        sum=sum+arr[i]-arr[i-k];
        if(sum%3==0){
            ans=make_pair(i-k+1,i);
            found=true;
        }
    }

    if(!found){
        ans=make_pair(-1,0);
    }
    if(ans.first==-1){
        cout<<"No Such Subarray Exists"<<endl;
    }
    else{
        for(int i=ans.first;i<=ans.second;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    vector<int> arr={84,23,45,12,56,82};
    int k=3;
    computeNumber(arr,k);
}