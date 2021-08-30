/*
    For a given array and an integer K, check if any array of size K
    exixts in the array such that concatenation of elementa form a 
    palindrome

    --> Approach 1
        Generate all subarrays of size K 
        Time complexity - O(n^2)

        Check if their concatination forms a palindrome
        Time Complexity - O(n)

        Total time complexity - O(n^3)
    --> Approach 2
        1. Store concatenation of initial K elements
        2. Iterate over the array and start deleting elements from 
           the start and adding elements from the end
        3. At each step, check if concatenation is a palindrome

        Time Complexity - O(n^2)
*/
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

bool isPalindrome(int n){
    int temp=n,number=0;
    while(temp>0){
        number=number*10+temp%10;
        temp=temp/10;
    }
    if(number==n){
        return true;
    }
    else{
        return false;
    }
}

int findPalindromicSubarray(vector<int> arr,int k){
    int num=0;

    for(int i=0;i<k;i++){
        num=num*10+arr[i];
    }

    if(isPalindrome(num)){
        return 0;
        // Indicating the array is from 0 to k-1
    }

    for(int j=k;j<arr.size();j++){
        num=(num%(int)pow(10,k-1))*10 + arr[j];
        if(isPalindrome(num)){
            return j-k+1;
        }
    }

    return -1;
}

int main(){
    vector<int> arr={2,3,5,1,1,5};
    int k=4;
    cout<<findPalindromicSubarray(arr,k);
}