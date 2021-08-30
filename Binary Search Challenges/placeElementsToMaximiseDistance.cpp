/*
    Given is an array with n elements that represents n 
    positions along a straignt line. Find K elements such
    that the minimum distance between any 2 elements is 
    the maximum possible

    -----> Approach 1
    Find all possible subsets of size K & compare the 
    minimum diatance between all of them

    -----> Approach 2 (Binary Search)
    1. Sort the array for bnary search technique
    2. Pick middle element as result and check for its feasibility
    3. If feasible, search the right half of the array with larger 
       minimum distance
    4. Else search the left half of the array

    Example : 
    1 2 7 5 1 12    K=3
    1 2 5 7 11 12    Sorted array
        Initialising the range left = 1, right = 12
        now calculating the mid of 12 ie 6
        now we checked the feasiblity of mid =6 and it is not
        so we update right as 6 now calculating mid = 3 (1, 5, 11)
        now mid = 3 comes as feasible solution so we update our left as 3
        left = 3, right = 6 mid = 4  ----> feasible (1, 5, 11)
        left = 4, right= 6 mid = 5 ---> (1, 7, 12)
        now if we update left as 5 than we have alredy calculated ans for mid=5
        and mid=6 is not feasible
*/

#include<iostream>
#include<algorithm>
using namespace std;

bool isFeasible(int mid,int arr[],int n,int k){
    int pos=arr[0];
    int elements=1;
    for(int i=0;i<n;i++){
        if(arr[i]-pos>=mid){
            pos=arr[i];
            elements++;
            if(elements==k){
                return true;
            }
        }
    }
    return false;
}

int largestMinimumdist(int arr[],int n,int k){
    sort(arr,arr+n);
    int result=-1;
    int left=1;
    int right=arr[n-1];
    while(left<right){
        int mid=(left+right)/2;
        if(isFeasible(mid,arr,n,k)){
            result=max(result,mid);
            left=mid+1;
        }
        else{
            right=mid;
        }
    }
    return result;
}

int main(){
    int arr[]={1 ,2 ,7 ,5 ,1 ,12};
    int n=6;
    int k=3;
    cout<<largestMinimumdist(arr,n,k);
    return 0;
}