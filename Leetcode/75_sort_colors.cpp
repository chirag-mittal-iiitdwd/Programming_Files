#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int k=0;
        int j=n-1;
        while(k<j){
            if(nums[k]==0){
                swap(nums[i],nums[k]);
                k++;
                i++;
            }
            else if(nums[k]==1){
                k++;
            }
            else{
                swap(nums[k],nums[j]);
                j--;
            }
        }
    }
};

void dnfSort(int arr[],int n){
    int i=0;
    int k=0;
    int j=n-1;
    while(k<j){
        if(arr[k]==0){
            swap(arr[i],arr[k]);
            k++;
            i++;
        }
        else if(arr[k]==1){
            k++;
        }
        else{
            swap(arr[k],arr[j]);
            j--;
        }
    }
}

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int end=n-1,start=0,mid=0;

        while(mid<=end){
            if(nums[mid]==0){
                swap(nums[start],nums[mid]);
                start++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[end]);
                end--;
            }
        }
    }
};