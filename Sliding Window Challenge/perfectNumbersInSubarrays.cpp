/*
    For a given array and an integer K, find the maximum perfect
    numbers in a subarray of size K.

    Perfect number is a number if it is equal to the sum of its
    proper divisors(positive divisors) except for the number itself.

    Example : number = 6, proper  divisor = [1 , 2 , 3]

    --> Approach 1
        Generate all subarrays of size K and count number of perfect
        numbers 
        Time Complexity - O(n*K)
    --> Trick 
        Convert the given array into a binary array with values 0 and 1
        only
    --> Approach 2
        1. Traverse the array and if the number at index i is a perfect number
           then replace value at ith index with '1', else with a '0'
        2. Initialize a variable to store sum of divisors
        3. Traverse every number less than arr[i] and add it to sum if it is a 
           divisor of arr[i]
        4. If the sum of all the divisors is equal to arr[i], then only the number 
           is a perfect number
        time complexity = O(n*sqrt(n))
*/

#include<iostream>
#include<cmath>
using namespace std;

bool isNumberPerfect(int n){
    int sum=1;
    // This sum will be storing the sum of perfect divisors of n
    for(int i=2;i<sqrt(n);i++){
        if((n%i)==0){
            if(i==(n/i)){
                sum+=i;
            }
            else{
                sum+=(i+(n/i));
            }
        }
    }
    if(sum==n && n!=1){
        return true;
    }
    return false;
}

int maxSum(int arr[],int n,int k){
    if(n<k){
        cout<<"Inavlid values\n";
        return -1;
    }
    int res=0;
    for(int i=0;i<k;i++){
        res+=arr[i];
    }
    int sum=res;
    for(int i=k;i<n;i++){
        sum+=arr[i]-arr[i-k];
        res=max(res,sum);
    }

    return res;
}

int maxNumberOfPercts(int arr[],int n,int k){
    for(int i=0;i<n;i++){
        if(isNumberPerfect(arr[i])){
            arr[i]=1;
        }
        else{
            arr[i]=0;
        }
    }

    return maxSum(arr,n,k);
}

int main(){
    int arr[]={28,2,3,6,496,99,8128,24};
    int k=4;
    int n=8;
    cout<<maxNumberOfPercts(arr,n,k);
}