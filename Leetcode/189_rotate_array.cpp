#include<bits/stdc++.h>
/*
    Soring
    Stack
    Queue
    Dynamic Programming
    Backtracking
    Linked List
    Sliding Window
    Tree
    Two Pointer
    Binary Search
    Maths
    Graph
    Greedy
    Heaps
    Hashing
*/
using namespace std;
#define int long long int
#define mod 1000000007
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    return 0;
}

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int>ans;
        int n=nums.size();
        k=k%n;
        int idx=n-k;
        
        for(int i=idx;i<n;i++){
            ans.push_back(nums[i]);
        }
        
        for(int i=0;i<n-k;i++){
            ans.push_back(nums[i]);
        }
        
        nums=ans;
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        int i=0,j=n-k-1;
        
        while(i<j){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
        
        i=n-k,j=n-1;
        while(i<j){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
        
        reverse(nums.begin(),nums.end());
    }
};